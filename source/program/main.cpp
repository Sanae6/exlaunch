#include "lib.hpp"
#include "nn/ro.h"
#include "nn/oe.h"

void tryInitSocket();
void Sys_Init();
void JIT_Execute_Init();
void MetaData_Init();
void Type_Init();
void Heap_Init();
void Finalizer_Init();
void Socket_Init();

MAKE_HOOK_T(void, socketInit, (void* gs), {
    impl(gs);
    exl::logger::log("\aConnected\n");
    Sys_Init();
    JIT_Execute_Init();
    MetaData_Init();
    Type_Init();
    Heap_Init();
    Finalizer_Init();
    Socket_Init();
    exl::logger::log("\aConnected\n");
});

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

//    INJECT_HOOK_OT(0x3e96c, socketInit);
    INJECT_HOOK_ST(_ZN10GameSystem4initEv, socketInit);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}