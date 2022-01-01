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

#include "CLIFile.hpp"
#include "MetaData.hpp"
#include "Type.hpp"
#include "Heap.hpp"
#include "Finalizer.hpp"
#include "System.Net.Sockets.Socket.hpp"
#include "MethodState.hpp"
#include "lib/diag/abort.hpp"
#include "lib/logger.hpp"

static void ShowUsage() {
	exl::logger::log("Usage:\n");
	exl::logger::log("\tdna [-v] <.Net executable to execute> [.Net executable arguments]\n");
	exl::logger::log("\n");
	exl::logger::log("\t-v  : Verbose output of files loaded and GC statistics\n");
	exl::logger::log("\t-vv : More verbose output, including methods JITted and types/arrays/generics use\n");
	exl::logger::log("\n");
	// EXL_ABORT(0x423);
}

void DNA_Init() {
	JIT_Execute_Init();
	MetaData_Init();
	Type_Init();
	Heap_Init();
	Finalizer_Init();
	Socket_Init();
}

void DNA_Load() {
	tCLIFile *pCLIFile;
	pCLIFile = CLIFile_Load("romfs:/DNA/TestProject.dll");

	if (pCLIFile->entryPoint) {
		char* argv[] = {"sex", "sex"};
		CLIFile_Execute(pCLIFile, 1, argv);
	} else {
		exl::logger::log("File %s has no entry point, skipping execution\n");
	}
}