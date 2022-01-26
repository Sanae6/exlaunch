#include "customPlayer.hpp"
#include "rs/util.hpp"

namespace ca {
    BirdPlayer::BirdPlayer(const char* name) : PlayerActorBase(name) {}
    void BirdPlayer::initPlayer(const al::ActorInitInfo& actorInfo, const PlayerInitInfo& playerInfo) {
        al::initActorWithArchiveName(this, actorInfo, sead::SafeString("PlayerActorHakoniwa"), nullptr);
        rs::initPlayerActorInfo(this, playerInfo);

        al::initNerve(this, &nrvBirdPlayerWait, 0);
    }

    void BirdPlayer::movement() {
        PlayerActorBase::movement();
        if (al::isPadTriggerA(-1)) {
            al::setVelocityOnlyV(this, 4.0f);
        }
    }

    void BirdPlayer::exeWait()
    {
        if (al::isFirstStep(this))
        {
            // do something
        }
    }

    namespace
    {
        NERVE_IMPL(BirdPlayer, Wait);
    }
}
