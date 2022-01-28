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
#include "RVA.hpp"
#include "MetaData.hpp"
#include "Thread.hpp"
#include "MetaDataTables.hpp"
#include "Type.hpp"

#include "System.Array.hpp"
#include "System.String.hpp"

#include "nn/fs.h"

// Is this exe/dll file for the .NET virtual machine?
#define DOT_NET_MACHINE 0x14c

typedef struct tFilesLoaded_ tFilesLoaded;
struct tFilesLoaded_ {
	tCLIFile *pCLIFile;
	tFilesLoaded *pNext;
};

// In .NET Core, the core libraries are split over numerous assemblies. For simplicity,
// the DNA corlib just puts them in one assembly
static STRING assembliesMappedToDnaCorlib[] = {
	(STRING) "mscorlib"
	// Also, "System.*" is implemented below
};
static int numAssembliesMappedToDnaCorlib = sizeof(assembliesMappedToDnaCorlib)/sizeof(STRING);

// Keep track of all the files currently loaded
static tFilesLoaded *pFilesLoaded = NULL;

tMetaData* CLIFile_GetMetaDataForLoadedAssembly(unsigned char *pLoadedAssemblyName) {
	tFilesLoaded *pFiles = pFilesLoaded;

	while (pFiles != NULL) {
		tCLIFile *pCLIFile = pFiles->pCLIFile;
		tMD_Assembly *pThisAssembly = (tMD_Assembly*)MetaData_GetTableRow(pCLIFile->pMetaData, MAKE_TABLE_INDEX(0x20, 1));
		if (strcmp((char*)pLoadedAssemblyName, (char*)pThisAssembly->name) == 0) {
			// Found the correct assembly, so return its meta-data
			return pCLIFile->pMetaData;
		}
		pFiles = pFiles->pNext;
	}

	Crash("Assembly %s is not loaded\n", pLoadedAssemblyName);
	FAKE_RETURN;
}

tMetaData* CLIFile_GetMetaDataForAssembly(unsigned char *pAssemblyName) {
	tFilesLoaded *pFiles;

	// Where applicable, redirect this assembly lookup into DNA's corlib
	// (e.g., mscorlib, System.Runtime, etc.)
	for (int i = 0; i < numAssembliesMappedToDnaCorlib; i++) {
		if (strcmp((char*) pAssemblyName, (char*) assembliesMappedToDnaCorlib[i]) == 0) {
			pAssemblyName = (STRING) "corlib";
			break;
		}
	}
	
	// Also redirect System.* into corlib for convenience
	if (strncmp("System.", (char*) pAssemblyName, 7) == 0) {
		pAssemblyName = (STRING) "corlib";
	}

	// Look in already-loaded files first
	pFiles = pFilesLoaded;
	while (pFiles != NULL) {
		tCLIFile *pCLIFile;
		tMD_Assembly *pThisAssembly;

		pCLIFile = pFiles->pCLIFile;
		// Get the assembly info - there is only ever one of these in the each file's metadata
		pThisAssembly = (tMD_Assembly*) MetaData_GetTableRow(pCLIFile->pMetaData, MAKE_TABLE_INDEX(0x20, 1));
		if (strcmp((char*) pAssemblyName, (char*) pThisAssembly->name) == 0) {
			// Found the correct assembly, so return its meta-data
			return pCLIFile->pMetaData;
		}
		pFiles = pFiles->pNext;
	}

	// Assembly not loaded, so load it if possible
	{
		tCLIFile *pCLIFile;
		unsigned char fileName[256];
		nn::util::SNPrintf((char*) fileName, 256, "content:/NetData/%s.dll", pAssemblyName);
		log_f(0, "Attempting to load %s\n", fileName);
		pCLIFile = CLIFile_Load((char*) fileName);
		if (pCLIFile == NULL) {
			Crash("Cannot load required assembly file: %s", fileName);
		}
		log_f(0, "Done attempting to load %s\n", fileName);
		return pCLIFile->pMetaData;
	}
}

tMD_TypeDef* CLIFile_FindTypeInAllLoadedAssemblies(STRING nameSpace, STRING name) {
	tFilesLoaded *pFiles = pFilesLoaded;
	while (pFiles != NULL) {
		tCLIFile *pCLIFile = pFiles->pCLIFile;

		tMD_TypeDef* typeDef = MetaData_GetTypeDefFromName(pCLIFile->pMetaData, nameSpace, name, NULL, /* assertExists */ 0);
		if (typeDef != NULL) {
			return typeDef;
		}

		pFiles = pFiles->pNext;
	}

	Crash("CLIFile_FindTypeInAllLoadedAssemblies(): Cannot find type %s.%s", nameSpace, name);
	return NULL;
}

void asdasdoasdad();

static void* LoadFileFromDisk(char *pFileName) {
	nn::fs::FileHandle f = {0};
	void *pData = NULL;

    log_f(0, "Among sus %s %p %p\n", pFileName, nn::fs::OpenFile, asdasdoasdad);
	nn::Result rc = nn::fs::OpenFile(&f, pFileName, nn::fs::OpenMode_Read/* |nn::fs::OpenMode_Binary */);
	log_f(0, "RC: %d", rc.GetInnerValueForDebug());
	if (rc.IsSuccess()) {
		s64 len = 0;
		rc = nn::fs::GetFileSize(&len, f);
		pData = mallocForever(len);
		if (pData != NULL) {
			rc = nn::fs::ReadFile(f, 0, pData, len);
			if (rc.IsFailure()) {
				dna::free(pData);
				pData = NULL;
			}
		}
		nn::fs::CloseFile(f);
	}

	return pData;
}

char* GetNullTerminatedString(PTR pData, int* length)
{
    *length = strlen((char*) pData) + 1;
    return (char*) pData;
}

static unsigned int GetU32(unsigned char *pSource, int* length) {
    unsigned int a, b, c, d;

    a = pSource[0];
    b = pSource[1];
    c = pSource[2];
    d = pSource[3];

    *length = 4;

    return (a >> 24) | (b >> 16) | (c >> 8) | d;
}

static tDebugMetaData* LoadDebugFile(PTR pData) {
    tDebugMetaData *pRet = TMALLOC(tDebugMetaData);
    tDebugMetaDataEntry* pPrevious = NULL;
    tDebugMetaDataEntry* pFirst = NULL;
    int moduleLength;
    int namespaceLength;
    int classLength;
    int methodLength;
    int intLength;
    int IdLength;

    while (*pData) {
        tDebugMetaDataEntry* pEntry = TMALLOC(tDebugMetaDataEntry);
        IdLength = 0;
        pEntry->sequencePointsCount = 0;
        pEntry->pModuleName = GetNullTerminatedString(pData, &moduleLength);
        pData += moduleLength;
        IdLength += moduleLength;
        pEntry->pNamespaceName = GetNullTerminatedString(pData, &namespaceLength);
        pData += namespaceLength;
        IdLength += namespaceLength;
        pEntry->pClassName = GetNullTerminatedString(pData, &classLength);
        pData += classLength;
        IdLength += classLength;
        pEntry->pMethodName = GetNullTerminatedString(pData, &methodLength);
        pData += methodLength;
        IdLength += methodLength;

        pEntry->pID = (char*)mallocForever((U32)IdLength + 1);
        IdLength = 0;
        strncpy(pEntry->pID, pEntry->pModuleName, moduleLength - 1);
        IdLength += moduleLength - 1;
        strncpy(pEntry->pID + IdLength, pEntry->pNamespaceName, namespaceLength - 1);
        IdLength += namespaceLength - 1;
        strncpy(pEntry->pID + IdLength, pEntry->pClassName, classLength - 1);
        IdLength += classLength - 1;
        strncpy(pEntry->pID + IdLength, pEntry->pMethodName, methodLength);
        IdLength += methodLength;

        pEntry->sequencePointsCount = GetU32(pData, &intLength);
        pData += intLength;
        for (int i = 0; i < pEntry->sequencePointsCount; i++) {
            int offset = GetU32(pData, &intLength);
            pEntry->sequencePoints[i] = offset;
            pData += intLength;
        }

        if (pPrevious != NULL) {
            pPrevious->next = pEntry;
        }

        if (pFirst == NULL) {
            pFirst = pEntry;
        }
        pPrevious = pEntry;
    }

    pPrevious->next = NULL;
    pRet->entries = pFirst;

    return pRet;
}

#include <strings.h>

static tCLIFile* LoadPEFile(void *pData) {
	tCLIFile *pRet = TMALLOC(tCLIFile);

	unsigned char *pMSDOSHeader = (unsigned char*)&(((unsigned char*)pData)[0]);
	unsigned char *pPEHeader;
	unsigned char *pPEOptionalHeader;
	unsigned char *pPESectionHeaders;
	unsigned char *pCLIHeader;
	unsigned char *pRawMetaData;

	int i;
	unsigned int lfanew;
	unsigned short machine;
	int numSections;
	unsigned int imageBase;
	int fileAlignment;
	unsigned int cliHeaderRVA, cliHeaderSize;
	unsigned int metaDataRVA, metaDataSize;
	tMetaData *pMetaData;

	pRet->pRVA = RVA();
	pRet->pMetaData = pMetaData = MetaData();

	lfanew = *(unsigned int*)&(pMSDOSHeader[0x3c]);
	pPEHeader = pMSDOSHeader + lfanew + 4;
	pPEOptionalHeader = pPEHeader + 20;
	pPESectionHeaders = pPEOptionalHeader + 224;

	machine = *(unsigned short*)&(pPEHeader[0]);
	if (machine != DOT_NET_MACHINE) {
		return NULL;
	}
	numSections = *(unsigned short*)&(pPEHeader[2]);

	imageBase = *(unsigned int*)&(pPEOptionalHeader[28]);
	fileAlignment = *(int*)&(pPEOptionalHeader[36]);

	for (i=0; i<numSections; i++) {
		unsigned char *pSection = pPESectionHeaders + i * 40;
		RVA_Create(pRet->pRVA, pData, pSection);
	}

	cliHeaderRVA = *(unsigned int*)&(pPEOptionalHeader[208]);
	cliHeaderSize = *(unsigned int*)&(pPEOptionalHeader[212]);

	pCLIHeader = (unsigned char*) RVA_FindData(pRet->pRVA, cliHeaderRVA);

	metaDataRVA = *(unsigned int*)&(pCLIHeader[8]);
	metaDataSize = *(unsigned int*)&(pCLIHeader[12]);
	pRet->entryPoint = *(unsigned int*)&(pCLIHeader[20]);
	pRawMetaData = (unsigned char*) RVA_FindData(pRet->pRVA, metaDataRVA);

	// Load all metadata
	{
		unsigned int versionLen = *(unsigned int*)&(pRawMetaData[12]);
		unsigned int ofs, numberOfStreams;
		void *pTableStream = NULL;
		unsigned int tableStreamSize;
		pRet->pVersion = &(pRawMetaData[16]);
		log_f(1, "CLI version: %s\n", pRet->pVersion);
		ofs = 16 + versionLen;
		numberOfStreams = *(unsigned short*)&(pRawMetaData[ofs + 2]);
		ofs += 4;

		for (i=0; i<(signed)numberOfStreams; i++) {
			unsigned int streamOffset = *(unsigned int*)&pRawMetaData[ofs];
			unsigned int streamSize = *(unsigned int*)&pRawMetaData[ofs+4];
			unsigned char *pStreamName = &pRawMetaData[ofs+8];
			void *pStream = pRawMetaData + streamOffset;
			ofs += (unsigned int)((strlen((char*)pStreamName)+4) & (~0x3)) + 8;
			if (strcasecmp((char*)pStreamName, "#Strings") == 0) {
				MetaData_LoadStrings(pMetaData, pStream, streamSize);
			} else if (strcasecmp(pStreamName, "#US") == 0) {
				MetaData_LoadUserStrings(pMetaData, pStream, streamSize);
			} else if (strcasecmp(pStreamName, "#Blob") == 0) {
				MetaData_LoadBlobs(pMetaData, pStream, streamSize);
			} else if (strcasecmp(pStreamName, "#GUID") == 0) {
				MetaData_LoadGUIDs(pMetaData, pStream, streamSize);
			} else if (strcasecmp(pStreamName, "#~") == 0) {
				pTableStream = pStream;
				tableStreamSize = streamSize;
			}
		}
		// Must load tables last
		if (pTableStream != NULL) {
			MetaData_LoadTables(pMetaData, pRet->pRVA, pTableStream, tableStreamSize);
		}
	}

	// Mark all generic definition types and methods as such
	for (i=pMetaData->tables.numRows[MD_TABLE_GENERICPARAM]; i>0; i--) {
		tMD_GenericParam *pGenericParam;
		IDX_TABLE ownerIdx;

		pGenericParam = (tMD_GenericParam*)MetaData_GetTableRow
			(pMetaData, MAKE_TABLE_INDEX(MD_TABLE_GENERICPARAM, i));
		ownerIdx = pGenericParam->owner;
		switch (TABLE_ID(ownerIdx)) {
			case MD_TABLE_TYPEDEF:
				{
					tMD_TypeDef *pTypeDef = (tMD_TypeDef*)MetaData_GetTableRow(pMetaData, ownerIdx);
					pTypeDef->isGenericDefinition = 1;
				}
				break;
			case MD_TABLE_METHODDEF:
				{
					tMD_MethodDef *pMethodDef = (tMD_MethodDef*)MetaData_GetTableRow(pMetaData, ownerIdx);
					pMethodDef->isGenericDefinition = 1;
				}
				break;
			default:
				Crash("Wrong generic parameter owner: 0x%08x", ownerIdx);
		}
	}

	// Mark all nested classes as such
	for (i=pMetaData->tables.numRows[MD_TABLE_NESTEDCLASS]; i>0; i--) {
		tMD_NestedClass *pNested;
		tMD_TypeDef *pParent, *pChild;

		pNested = (tMD_NestedClass*)MetaData_GetTableRow(pMetaData, MAKE_TABLE_INDEX(MD_TABLE_NESTEDCLASS, i));
		pParent = (tMD_TypeDef*)MetaData_GetTableRow(pMetaData, pNested->enclosingClass);
		pChild = (tMD_TypeDef*)MetaData_GetTableRow(pMetaData, pNested->nestedClass);
		pChild->pNestedIn = pParent;
	}

	return pRet;
}

tCLIFile* CLIFile_Load(char *pFileName) {
	void *pRawFile;
    void* pRawDebugFile;
	tCLIFile *pRet;
	tFilesLoaded *pNewFile;

	pRawFile = LoadFileFromDisk(pFileName);

	if (pRawFile == NULL) {
		Crash("Cannot load file: %s", pFileName);
	}

	log_f(1, "\nLoading file: %s\n", pFileName);

	pRet = LoadPEFile(pRawFile);
	pRet->pFileName = (char*)mallocForever((U32)strlen(pFileName) + 1);
	strcpy(pRet->pFileName, pFileName);

    // Assume it ends in .dll
    char* pDebugFileName = (char*)mallocForever((U32)strlen(pFileName) + 1);
    U32 fileLengthWithoutExt = strlen(pFileName) - 3;
    strncpy(pDebugFileName, pFileName, fileLengthWithoutExt);
    strncpy(pDebugFileName + fileLengthWithoutExt, "wdb", 3);
    *(pDebugFileName + fileLengthWithoutExt + 3) = '\0';

    pRawDebugFile = LoadFileFromDisk(pDebugFileName);
    if (pRawDebugFile == NULL) {
        log_f(1, "\nUnable to load debug file: %s\n", pDebugFileName);
    }
    else {
        log_f(1, "\nLoaded debug file: %s\n", pDebugFileName);
        pRet->pDebugFileName = pDebugFileName;
        pRet->pMetaData->debugMetadata = LoadDebugFile((PTR)pRawDebugFile);
    }

	// Record that we've loaded this file
	pNewFile = TMALLOCFOREVER(tFilesLoaded);
	pNewFile->pCLIFile = pRet;
	pNewFile->pNext = pFilesLoaded;
	pFilesLoaded = pNewFile;

	return pRet;
}

I32 CLIFile_Execute(tCLIFile *pThis, int argc, char **argp) {
	tThread *pThread;
	HEAP_PTR args;
	int i;

	// Create a string array for the program arguments
	// Don't include the argument that is the program name.
	argc--;
	argp++;
	args = SystemArray_NewVector(types[TYPE_SYSTEM_ARRAY_STRING], argc);
	Heap_MakeUndeletable(args);
	for (i = 0; i < argc; i++) {
		HEAP_PTR arg = SystemString_FromCharPtrASCII((U8*) argp[i]);
		SystemArray_StoreElement(args, i, (PTR)&arg);
	}

	// Create the main application thread
	pThread = Thread();
	Thread_SetEntryPoint(pThread, pThis->pMetaData, pThis->entryPoint, (PTR)&args, sizeof(void*));

	return Thread_Execute();
}

void CLIFile_GetHeapRoots(tHeapRoots *pHeapRoots) {
	tFilesLoaded *pFile;

	pFile = pFilesLoaded;
	while (pFile != NULL) {
		MetaData_GetHeapRoots(pHeapRoots, pFile->pCLIFile->pMetaData);
		pFile = pFile->pNext;
	}
}
