#include "lib.hpp"

namespace al {
    class LiveActor;
    class Scene {
    public:
        virtual void control() {}
    };
    void setTransY(LiveActor*, float);
};
namespace rs { al::LiveActor* getPlayerActor(const al::Scene*); };

class StageScene : public al::Scene {
public:
    void control() override;
};
void controlLol(StageScene* scene) {
    auto actor = rs::getPlayerActor(scene);
    al::setTransY(actor, 1000.0f);
}
MAKE_HOOK_T(void, controlLol, (StageScene* scene), {
    impl(scene);
    controlLol(scene);
});
extern "C" void exl_main(void* x0, void* x1) {
    /* Setup hooking enviroment. */
    envSetOwnProcessHandle(exl::util::proc_handle::Get());
    exl::hook::Initialize();

    INJECT_HOOK_T(ctrlx, controlLol);

    /*
    For sysmodules/applets, you have to call the entrypoint when ready
    exl::hook::CallTargetEntrypoint(x0, x1);
    */
}

extern "C" NORETURN void exl_exception_entry() {
    /* TODO: exception handling */
    EXL_ABORT(0x420);
}