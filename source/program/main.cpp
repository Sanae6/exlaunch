#include "lib.hpp"
#include "nn/ro.h"
#include "nn/oe.h"

void tryInitSocket();

MAKE_HOOK_T(void, il2cpp_init, (const char* name), {
    impl(name);
    // nn::oe::FinishStartupLogo();
    // tryInitSocket();
    // exl::logger::log("sex\n");
});

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

    // INJECT_HOOK_OT(0x3e96c, il2cpp_init);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}