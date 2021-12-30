#include "lib.hpp"
#include "game/StageScene/StageScene.h"
#include "rs/util.hpp"
#include "al/util.hpp"
#include "nn/ro.h"
#include "sead/basis/seadNew.hpp"
#include "game/System/GameSystem.h"
#include "al/factory/ProjectActorFactory.h"
#include <functional>

int aaaaa = 0;
float y = 1000.0f;
void controlLol(StageScene* scene) {
    auto actor = rs::getPlayerActor(scene);
    float factor = 3.0f;
    if (al::isPadHoldL(-1)) factor *= 3.0f;
    if (al::isPadHoldUp(-1)) y += factor;
    if (al::isPadHoldDown(-1)) y -= factor;
    if (al::isPadHoldR(-1)) al::setTransY(actor, y);
}

MAKE_HOOK_T(void, controlLol, (StageScene* scene), {
    controlLol(scene);
    impl(scene);
});

bool tryInitSocket();

MAKE_HOOK_T(void, socketInit, (void* gs), {
    impl(gs);

    exl::logger::log("\aConnected\n");
});

MAKE_HOOK(bool, snapshotMode, (void* sceneMaybe), { return false; });

MAKE_ASM(nop, R"(
    NOP
)");

MAKE_ASM(amiiboBase, R"(
    MOV X0, #0
    RET
)");

#include <new>

MAKE_HOOK(void, pafCtor, (ProjectActorFactory* paf), {
    new (paf) al::ActorFactory("アクター生成");
    paf->actorTable = actorEntries;
    paf->factoryCount = sizeof(actorEntries)/sizeof(actorEntries[0]);
});

extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

    INJECT_HOOK_ST(_ZN10GameSystem4initEv, socketInit);
    INJECT_HOOK_ST(_ZN10StageScene7controlEv, controlLol);
    INJECT_HOOK_S(_ZN2rs21isTriggerSnapShotModeEPKN2al18IUseSceneObjHolderE, snapshotMode);
    INJECT_HOOK_S(_ZN19ProjectActorFactoryC2Ev, pafCtor);

    // REPLACE_ASM_O(0x5359D8, gsBranch, 1);
    REPLACE_ASM_O(0x1B3F0C, nop, 1);
    REPLACE_ASM_S(_ZN2rs16isHoldAmiiboModeEPKN2al18IUseSceneObjHolderE, amiiboBase, 2);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}