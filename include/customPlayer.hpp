#include "al/LiveActor/LiveActor.h"
#include "game/Player/PlayerActorBase.h"
#include "al/util.hpp"
#include "al/sensor/SensorMsg.h"
#include "al/util/NerveUtil.h"

namespace ca {
    class BirdPlayer : public PlayerActorBase {
    public:
        BirdPlayer(const char* name);
        void initPlayer(const al::ActorInitInfo&, const PlayerInitInfo&) override;
        void movement();
        void exeWait();
    };

    namespace
    {
        NERVE_HEADER(BirdPlayer, Wait)
    }
}