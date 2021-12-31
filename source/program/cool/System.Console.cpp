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

#include "Compat.h"
#include "Sys.h"

#include "System.String.h"

#include "MetaData.h"
#include "Types.h"
#include "Type.h"

#include "nn/util.h"

tAsyncCall* System_Console_Write(PTR pThis_, PTR pParams, PTR pReturnValue) {
	HEAP_PTR string;
	STRING2 str;
	U32 i, strLen;

	string = *(HEAP_PTR*)pParams;
	if (string != NULL) {
#define SUB_LEN 128
		unsigned char str8[SUB_LEN+1] = {};
		U32 start = 0;
		str = SystemString_GetString(string, &strLen);
		while (strLen > 0) {
			int len = strLen > SUB_LEN ? SUB_LEN : strLen;
			memcpy(str8, str, len);
		}
	}

	return NULL;
}

static U32 Internal_ReadKey_Check(PTR pThis_, PTR pParams, PTR pReturnValue, tAsyncCall *pAsync) {
	*(U32*)pReturnValue = 0xFFFFFFFF;
	return 1;
}

tAsyncCall* System_Console_Internal_ReadKey(PTR pThis_, PTR pParams, PTR pReturnValue) {
	tAsyncCall *pAsync = TMALLOC(tAsyncCall);

	pAsync->sleepTime = -1;
	pAsync->checkFn = Internal_ReadKey_Check;
	pAsync->state = NULL;

	return pAsync;
}

tAsyncCall* System_Console_Internal_KeyAvailable(PTR pThis_, PTR pParams, PTR pReturnValue) {
	*(U32*)pReturnValue = 0;
	return NULL;
}
