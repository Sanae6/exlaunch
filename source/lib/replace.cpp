#include "lib/util/rw_pages.hpp"

#include "replace.hpp"
#include <cstring>

namespace exl::replace {
    void ReplaceData(uintptr_t target, const uintptr_t source, size_t size) {
        exl::util::RwPages control(target, size);

        std::memcpy((void*)control.m_Rw, (const void*)source, size);
    }
}