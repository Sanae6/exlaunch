#include "types.h"
#include "lib.hpp"
#include "nn/ro.h"

namespace exl::ro {
    uintptr_t GetSymbol(const char* name) {
        uintptr_t address = 0;
        Result rc = nn::ro::LookupSymbol(&address, name);
        if (R_FAILED(rc)) EXL_ABORT(0x421);
        return address;
    }
}