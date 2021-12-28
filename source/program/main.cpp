#include "lib.hpp"
#include "game/StageScene/StageScene.h"
#include "rs/util.hpp"
#include "al/util.hpp"
#include "nn/ro.h"
#include "sead/basis/seadNew.hpp"


int aaaaa = 0;
float y = 1000.0f;
void controlLol(StageScene* scene) {
    auto actor = rs::getPlayerActor(scene);
    float factor = 3.0f;
    if (al::isPadHoldL(-1)) factor *=3.0f;
    if (al::isPadHoldUp(-1)) y += factor;
    if (al::isPadHoldDown(-1)) y -= factor;
    if (al::isPadHoldR(-1)) al::setTransY(actor, y);
}

MAKE_HOOK_T(void, controlLol, (StageScene* scene), {
    controlLol(scene);
    impl(scene);
});

void tryInitSocket();

MAKE_HOOK_T(void, socketInit, (void* gs), {
    impl(gs);
    tryInitSocket();
});

MAKE_HOOK_T(bool, snapshotMode, (void* sceneMaybe), {

    return false;
});

extern "C" void _ZN10StageScene7controlEv(StageScene*);
extern "C" void _ZN10GameSystem4initEv(void*);
extern "C" bool _ZN2rs21isTriggerSnapShotModeEPKN2al18IUseSceneObjHolderE(void*);
extern "C" u32 _ZN2rs19isTriggerAmiiboModeEPKN2al18IUseSceneObjHolderE[];
extern "C" u32 _ZN2rs16isHoldAmiiboModeEPKN2al18IUseSceneObjHolderE[];

asm(R"(
.global nopBase
nopBase:
    NOP

.global amiiboBase
amiiboBase:
    MOV X0, #0
    RET
)");

extern const u32 nopBase;
extern const u32 amiiboBase[];

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

    INJECT_HOOK_T(_ZN10GameSystem4initEv, socketInit);
    INJECT_HOOK_T(_ZN10StageScene7controlEv, controlLol);
    INJECT_HOOK_T(_ZN2rs21isTriggerSnapShotModeEPKN2al18IUseSceneObjHolderE, snapshotMode);

    exl::replace::ReplaceData(exl::hook::GetTargetOffset(0x1B3F0C), (uintptr_t)&nopBase, sizeof(u32));
    exl::replace::ReplaceData((uintptr_t)_ZN2rs16isHoldAmiiboModeEPKN2al18IUseSceneObjHolderE, (uintptr_t)&amiiboBase, sizeof(u32) * 2);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}