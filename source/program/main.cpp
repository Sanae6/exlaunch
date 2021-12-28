#include "lib.hpp"
#include "game/StageScene/StageScene.h"
#include "rs/util.hpp"
#include "al/util.hpp"
#include "nn/ro.h"
#include "logger.hpp"
#include "sead/basis/seadNew.hpp"


int aaaaa = 0;
void controlLol(StageScene* scene) {
    auto actor = rs::getPlayerActor(scene);
    al::setTransY(actor, 1000.0f);
    if (aaaaa++ > 300) {
        aaaaa = 0;
        exl::logger::log("pogu frame");
    }
}
uintptr_t getSymbol(const char* name) {
    uintptr_t outaddr;
    R_ABORT_UNLESS(nn::ro::LookupSymbol(&outaddr, name));
    return outaddr;
}
MAKE_HOOK_T(void, controlLol, (StageScene* scene), {
    controlLol(scene);
    impl(scene);
});

void tryInitSocket();

class Aaah {
public:
    int fuck = 0;
};

void aaaa() {
    Aaah* aaah = new Aaah();
    aaah->fuck = 10;
    
    tryInitSocket();
}

MAKE_HOOK_T(void, socketInit, (void* gs), {
    impl(gs);
    aaaa();
});

extern "C" void _ZN10StageScene7controlEv(StageScene*);
extern "C" void _ZN10GameSystem4initEv(void*);

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

    INJECT_HOOK_T(_ZN10GameSystem4initEv, socketInit);
    INJECT_HOOK_T(_ZN10StageScene7controlEv, controlLol);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}