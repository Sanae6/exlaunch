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

#ifdef _WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif // _WIN32

#include "Compat.hpp"
#include "Sys.hpp"

#include "MetaData.hpp"
#include "Types.hpp"

#include "lib.hpp"
#include "nn/util.h"
#include "lib/nx/kernel/svc.h"

void Crash(char *pMsg, ...) {
	va_list va;

	exl::logger::log("\n\n*** CRASH ***\n");
	va_start(va, pMsg);
	exl::logger::log(pMsg, va);
	va_end(va);
	exl::logger::log("\n\n");

	svcExitProcess();
}

U32 logLevel = 0;

void log_f(U32 level, char *pMsg, ...) {
	va_list va;

//	if (logLevel >= level) {
		va_start(va, pMsg);
		exl::logger::log(pMsg, va);
		va_end(va);
//	}
}

static char methodName[2048];
char* Sys_GetMethodDesc(tMD_MethodDef *pMethod) {
	U32 i;

	nn::util::SNPrintf(methodName, 2048, "%s.%s.%s(", pMethod->pParentType->nameSpace, pMethod->pParentType->name, pMethod->name);
	for (i=METHOD_ISSTATIC(pMethod)?0:1; i<pMethod->numberOfParameters; i++) {
		if (i > (U32)(METHOD_ISSTATIC(pMethod)?0:1)) {
			nn::util::SNPrintf(strchr(methodName, 0), 2048, ",");
		}
		nn::util::SNPrintf(strchr(methodName, 0), 2048, (const char*) pMethod->pParams[i].pTypeDef->name);
	}
	nn::util::SNPrintf(strchr(methodName, 0), 2048, ")");
	return methodName;
}

#include "nn/init.h"
#include "nn/mem.h"

nn::mem::StandardAllocator* allocator;

void Sys_Init() {
    exl::logger::log("Getting allocator\n");
	allocator = nn::init::GetAllocator();
    exl::logger::log("Legally acquired allocator %p\n", allocator);
}

namespace dna {
    void* malloc(size_t size) {
        return allocator->Allocate(size);
    }

    void* realloc(void* address, size_t size) {
        return allocator->Reallocate(address, size);
    }

    void free(void* address) {
        allocator->Free(address);
    }
}

static U32 mallocForeverSize = 0;
// malloc() some memory that will never need to be resized or freed.
void* mallocForever(U32 size) {
	mallocForeverSize += size;
	log_f(3, "--- mallocForever: TotalSize %d\n", mallocForeverSize);
	return dna::malloc(size);
}

char* stringOrNull(char* str) {
	char* loc = new char[512];
	memset(loc, 0, 512);
	nn::util::SNPrintf(loc, 512, "%p", str);
	if (str != NULL) return str;
	return "NULL";
}

/*
#ifdef _DEBUG
void* mallocTrace(int s, char *pFile, int line) {
	//printf("MALLOC: %s:%d %d\n", pFile, line, s);
#undef malloc
	return malloc(s);
}
#endif
*/

U64 msTime() {
#ifdef _WIN32
	static LARGE_INTEGER freq = {0,0};
	LARGE_INTEGER time;
	if (freq.QuadPart == 0) {
		QueryPerformanceFrequency(&freq);
	}
	QueryPerformanceCounter(&time);
	return (time.QuadPart * 1000) / freq.QuadPart;
#else
	struct timeval tp;
	U64 ms;
	gettimeofday(&tp,NULL);
	ms = tp.tv_sec;
	ms *= 1000;
	ms += ((U64)tp.tv_usec)/((U64)1000);
	return ms;
#endif
}

#if defined(DIAG_METHOD_CALLS) || defined(DIAG_OPCODE_TIMES) || defined(DIAG_GC) || defined(DIAG_TOTAL_TIME)
U64 microTime() {
#ifdef _WIN32
	static LARGE_INTEGER freq = {0,0};
	LARGE_INTEGER time;
	if (freq.QuadPart == 0) {
		QueryPerformanceFrequency(&freq);
	}
	QueryPerformanceCounter(&time);
	return (time.QuadPart * 1000000) / freq.QuadPart;
#else
	struct timeval tp;
	U64 ms;
	gettimeofday(&tp,NULL);
	ms = tp.tv_sec;
	ms *= 1000000;
	ms += ((U64)tp.tv_usec);
	return ms;
#endif
}
#endif

void SleepMS(U32 ms) {
// #ifdef _WIN32
// 	Sleep(ms);
// #else
// 	sleep(ms / 1000);
// 	usleep((ms % 1000) * 1000);
// #endif
}