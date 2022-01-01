#pragma once
#include <stddef.h>

void dna_init();

typedef struct dnaCLIFile dnaCLIFile;
typedef enum dnaCallbackType {
    FileOpen,
    FileRead,
    FileWrite,
    FileCreate,
    FileDelete


} dnaCallbackType;

dnaCLIFile* dna_file_load(char* name, size_t nameSize, void* data, size_t dataSize);
char* dna_file_get_name(dnaCLIFile* file);

/*
 * Callbacks are used to store implementations for many required functions like file or socket functions
 */
void dna_callback_set(dnaCallbackType type, void* callbackFunction);
void* dna_callback_get(dnaCallbackType type);

/*
 * Callback typedefs
 */

