// Copyright (c) 2012 DotNetAnywhere
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "Compat.hpp"
#include "Sys.hpp"

#include "System.Net.Sockets.Socket.hpp"

#include "System.Array.hpp"

#include "nn/nifm.h"
#include "nn/socket.h"
#include "syssocket/sockdefines.h"
// #include "inet/protocoltypes.h"
#include "lib/nx/result.h"


void Socket_Init() {
	nn::nifm::Initialize();
	nn::nifm::SubmitNetworkRequestAndWait();
}

tAsyncCall* System_Net_Sockets_Internal_CreateSocket(PTR pThis_, PTR pParams, PTR pReturnValue) {

	Result s;

	U32 family = INTERNALCALL_PARAM(0, U32);
	U32 type = INTERNALCALL_PARAM(4, U32);
	U32 proto = INTERNALCALL_PARAM(8, U32);
	U32 *pError = INTERNALCALL_PARAM(12, U32*);

	*(void**)pReturnValue = NULL;

	s = nn::socket::Socket(family, type, proto);

	if (s == -1) {
		// Error
		*pError = s;
		s = 0;
	} else {
		*pError = 0;
	}

	nn::socket::Fcntl(s, F_SETFL, O_NONBLOCK);
	

	*(int*)pReturnValue = s;

	return NULL;
}

tAsyncCall* System_Net_Sockets_Internal_Bind(PTR pThis_, PTR pParams, PTR pReturnValue) {
	struct sockaddr sa;

	int s = INTERNALCALL_PARAM(0, int);
	U32 addr = INTERNALCALL_PARAM(4, U32);
	U32 port = INTERNALCALL_PARAM(8, U32);
	U32 *pError = INTERNALCALL_PARAM(12, U32*);

	sa.family = AF_INET;
	sa.address.data = addr;
	sa.port = nn::socket::InetHtons(port);

	*pError = R_FAILED(nn::socket::Bind(s, (struct sockaddr*)&sa, sizeof(sa)));

	return NULL;
}

tAsyncCall* System_Net_Sockets_Internal_Close(PTR pThis_, PTR pParams, PTR pReturnValue) {

	int s = INTERNALCALL_PARAM(0, int);

	nn::socket::Close(s);

	return NULL;
}

tAsyncCall* System_Net_Sockets_Internal_Listen(PTR pThis_, PTR pParams, PTR pReturnValue) {
	int s = INTERNALCALL_PARAM(0, int);
	U32 backlog = INTERNALCALL_PARAM(4, U32);
	U32 *pError = INTERNALCALL_PARAM(8, U32*);

	*pError = nn::socket::Listen(s, backlog);

	return NULL;
}

static U32 Accept_Check(PTR pThis_, PTR pParams, PTR pReturnValue, tAsyncCall *pAsync) {
	int s = INTERNALCALL_PARAM(0, int);
	U32 *pError = INTERNALCALL_PARAM(4, U32*);
	Result newS;

	newS = (int)nn::socket::Accept(s, NULL, 0);
	if (newS == -1) {
		// Blocked or error
		if (newS == EWOULDBLOCK) {
			return 0;
		} else {
			*(U32*)pReturnValue = 0;
			*pError = newS;
			return 1;
		}
	} else {
		*(U32*)pReturnValue = newS;
		*pError = 0;
		return 1;
	}
}

tAsyncCall* System_Net_Sockets_Internal_Accept(PTR pThis_, PTR pParams, PTR pReturnValue) {
	U32 ret = Accept_Check(pThis_, pParams, pReturnValue, NULL);
	if (ret) {
		return NULL;
	} else {
		tAsyncCall *pAsync = TMALLOC(tAsyncCall);
		pAsync->sleepTime = -1;
		pAsync->checkFn = Accept_Check;
		pAsync->state = NULL;
		return pAsync;
	}
}

static U32 Connect_Check(PTR pThis_, PTR pParams, PTR pReturnValue, tAsyncCall *pAsync) {
	struct sockaddr sa;
	Result r;

	int s = INTERNALCALL_PARAM(0, int);
	U32 addr = INTERNALCALL_PARAM(4, U32);
	U32 port = INTERNALCALL_PARAM(8, U32);
	U32 *pError = INTERNALCALL_PARAM(12, U32*);

	sa.family = AF_INET;
	sa.address.data = addr;
	sa.port = nn::socket::InetHtons(port);

	r = nn::socket::Connect(s, (struct sockaddr*)&sa, sizeof(sa));
	if (r == 0) {
		*pError = 0;
		return 1;
	} else {
		if (r == EINPROGRESS || r == EALREADY) {
			// Still waiting for connection
			return 0;
		} else {
			if (r == EISCONN) {
				// The connection is fine
				r = 0;
			}
			// Connection failed
			*pError = r;
			return 1;
		}
	}
}

tAsyncCall* System_Net_Sockets_Internal_Connect(PTR pThis_, PTR pParams, PTR pReturnValue) {
	U32 ret = Connect_Check(pThis_, pParams, pReturnValue, NULL);
	if (ret) {
		return NULL;
	} else {
		tAsyncCall *pAsync = TMALLOC(tAsyncCall);
		pAsync->sleepTime = -1;
		pAsync->checkFn = Connect_Check;
		pAsync->state = NULL;
		return pAsync;
	}
}

typedef struct tSendRecvState_ tSendRecvState;
struct tSendRecvState_ {
	// The number of bytes we've currently received
	U32 count;
};

static U32 Receive_Check(PTR pThis_, PTR pParams, PTR pReturnValue, tAsyncCall *pAsync) {
	PTR buffer;
	Result r;
	tSendRecvState *pState = (tSendRecvState*)pAsync->state;

	int s = INTERNALCALL_PARAM(0, int);
	HEAP_PTR bufferArray = INTERNALCALL_PARAM(4, HEAP_PTR);
	U32 ofs = INTERNALCALL_PARAM(8, U32);
	U32 size = INTERNALCALL_PARAM(12, U32);
	U32 flags = INTERNALCALL_PARAM(16, U32);
	U32 *pError = INTERNALCALL_PARAM(20, U32*);

	buffer = SystemArray_GetElements(bufferArray) + ofs + pState->count;

	r = nn::socket::Recv(s, buffer, size, flags);

	if (r > 0) {
		pState->count += r;
		if (pState->count >= size) {
			// Got all required data
			*(U32*)pReturnValue = pState->count;
			*pError = 0;
			return 1;
		} else {
			// Still more data to come
			return 0;
		}
	} else if (r == 0) {
		// Connection has been closed, so finish
		*(U32*)pReturnValue = pState->count;
		*pError = 0;
		return 1;
	} else {
		int err = (int)r;
	//printf("Receive_Check: errno=%d\n", err);
#ifdef _WIN32
		if (err == WSAEINPROGRESS || err == WSAEWOULDBLOCK) {
#else
		if (err == EAGAIN) {
#endif
			// Still waiting for data
			return 0;
		} else {
			*(U32*)pReturnValue = pState->count;
			*pError = err;
			return 1;
		}
	}
}

tAsyncCall* System_Net_Sockets_Internal_Receive(PTR pThis_, PTR pParams, PTR pReturnValue) {
	U32 ok;
	tAsyncCall *pAsync = TMALLOC(tAsyncCall);
	tSendRecvState *pState = TMALLOC(tSendRecvState);
	pAsync->sleepTime = -1;
	pAsync->checkFn = Receive_Check;
	pAsync->state = (PTR)pState;
	pState->count = 0;
	ok = Receive_Check(pThis_, pParams, pReturnValue, pAsync);
	if (ok) {
		free(pState);
		free(pAsync);
		return NULL;
	} else {
		return pAsync;
	}
}

static U32 Send_Check(PTR pThis_, PTR pParams, PTR pReturnValue, tAsyncCall *pAsync) {
	PTR buffer;
	int r;
	tSendRecvState *pState = (tSendRecvState*)pAsync->state;

	int s = INTERNALCALL_PARAM(0, int);
	HEAP_PTR bufferArray = INTERNALCALL_PARAM(4, HEAP_PTR);
	U32 ofs = INTERNALCALL_PARAM(8, U32);
	U32 size = INTERNALCALL_PARAM(12, U32);
	U32 flags = INTERNALCALL_PARAM(16, U32);
	U32 *pError = INTERNALCALL_PARAM(20, U32*);

	buffer = SystemArray_GetElements(bufferArray) + ofs + pState->count;

	r = nn::socket::Send(s, buffer, size, flags);
	//printf("Send_Check: r=%d\n", r);

	if (r >= 0) {
		pState->count += r;
		if (pState->count >= size) {
			// All data sent
			*(U32*)pReturnValue = pState->count;
			*pError = 0;
			return 1;
		} else {
			// Still more data to come
			return 0;
		}
	} else {
		if (r == EAGAIN) {
			return 0;
		} else {
			*(U32*)pReturnValue = pState->count;
			*pError = r;
			return 1;
		}
	}
}

tAsyncCall* System_Net_Sockets_Internal_Send(PTR pThis_, PTR pParams, PTR pReturnValue) {
	U32 ok;
	tAsyncCall *pAsync = TMALLOC(tAsyncCall);
	tSendRecvState *pState = TMALLOC(tSendRecvState);
	pAsync->sleepTime = -1;
	pAsync->checkFn = Receive_Check;
	pAsync->state = (PTR)pState;
	pState->count = 0;
	ok = Send_Check(pThis_, pParams, pReturnValue, pAsync);
	if (ok) {
		free(pState);
		free(pAsync);
		return NULL;
	} else {
		return pAsync;
	}
}