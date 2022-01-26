#include "types.h"
#include "lib.hpp"
#include "nn/ro.h"

namespace exl::ro {
    uintptr_t GetSymbol(const char* name) {
        uintptr_t address = 0;
        nn::Result rc = nn::ro::LookupSymbol(&address, name);
        if (rc.IsFailure()) EXL_ABORT(0x421);
        return address;
    }
}