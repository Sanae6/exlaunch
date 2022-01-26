#pragma once

#include "game/Player/PlayerActorBase.h"
#include "game/Interfaces/IUseDimension.h"

namespace al {
class FootPrintHolder;
class HitSensor;
class WaterSurfaceFinder;
}  // namespace al

class PlayerInfo;
class PlayerConst;
class PlayerInput;
class PlayerTrigger;
class HackCap;
class ActorDimensionKeeper;
class PlayerModelHolder;
class PlayerModelChangerHakoniwa;
class PlayerAnimator;
class PlayerColliderHakoniwa;
class PlayerPuppet;
class PlayerAreaChecker;
class PlayerOxygen;
class PlayerDamageKeeper;
class PlayerDemoActionFlag;
class PlayerCapActionHistory;
class PlayerCapManHeroEyesControl;
class PlayerContinuousJump;
class PlayerContinuousLongJump;
class PlayerCounterAfterUpperPunch;
class PlayerCounterForceRun;
class PlayerCounterIceWater;
class PlayerCounterQuickTurnJump;
class PlayerWallActionHistory;
class PlayerBindKeeper;
class PlayerCarryKeeper;
class PlayerEquipmentUser;
class PlayerHackKeeper;
class PlayerFormSensorCollisionArranger;
class PlayerJumpMessageRequest;
class PlayerSandSinkAffect;
class PlayerSpinCapAttack;
class PlayerActionDiveInWater;
class PlayerEffect;
class PlayerEyeSensorHitHolder;
class PlayerPushReceiver;
class PlayerHitPush;
class PlayerExternalVelocity;
class PlayerJointControlKeeper;
class PlayerPainPartsKeeper;
class PlayerRecoverySafetyPoint;
class PlayerRippleGenerator;
class PlayerSeparateCapFlag;
class PlayerWetControl;
class PlayerStainControl;
class GaugeAir;
class WaterSurfaceShadow;
class WorldEndBorderKeeper;
class PlayerSeCtrl;
class PlayerStateWait;
class PlayerStateSquat;
class PlayerStateRunHakoniwa2D3D;
class PlayerStateSlope;
class PlayerStateRolling;
class PlayerStateSpinCap;
class PlayerStateJump;
class PlayerStateCapCatchPop;
class PlayerStateWallAir;
class PlayerStateWallCatch;
class PlayerStateGrabCeil;
class PlayerStatePoleClimb;
class PlayerStateHipDrop;
class PlayerStateHeadSliding;
class PlayerStateLongJump;
class PlayerStateFallHakoniwa;
class PlayerStateSandSink;
class ActorStateSandGeyser;
class PlayerStateRise;
class PlayerStateSwim;
class PlayerStateDamageLife;
class PlayerStateDamageSwim;
class PlayerStateDamageFire;
class PlayerStatePress;
class PlayerStateBind;
class PlayerStateHack;
class PlayerStateEndHack;
class PlayerStateCameraSubjective;
class PlayerStateAbyss;
class PlayerJudgeAirForceCount;
class PlayerJudgeCameraSubjective;
class PlayerJudgeCapCatchPop;
class PlayerJudgeDeadWipeStart;
class PlayerJudgeDirectRolling;
class PlayerJudgeEnableStandUp;
class PlayerJudgeForceLand;
class PlayerJudgeForceSlopeSlide;
class PlayerJudgeForceRolling;
class PlayerJudgeGrabCeil;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInWater;
class PlayerJudgeInvalidateInputFall;
class PlayerJudgeLongFall;
class PlayerJudgeOutInWater;
class PlayerJudgeRecoveryLifeFast;
class PlayerJudgeSandSink;
class PlayerJudgeSpeedCheckFall;
class PlayerJudgeStartHipDrop;
class PlayerJudgeStartRise;
class PlayerJudgeStartRolling;
class PlayerJudgeStartRun;
class PlayerJudgeStartSquat;
class PlayerJudgeStartWaterSurfaceRun;
class PlayerJudgeSlopeSlide;
class PlayerJudgePoleClimb;
class PlayerJudgePreInputJump;
class PlayerJudgePreInputCapThrow;
class PlayerJudgePreInputHackAction;
class HackCapJudgePreInputHoveringJump;
class HackCapJudgePreInputSeparateThrow;
class HackCapJudgePreInputSeparateJump;
class PlayerJudgeWallCatch;
class PlayerJudgeWallCatchInputDir;
class PlayerJudgeWallHitDown;
class PlayerJudgeWallHitDownForceRun;
class PlayerJudgeWallHitDownRolling;
class PlayerJudgeWallKeep;

class PlayerActorHakoniwa : PlayerActorBase, IUseDimension {
    PlayerInfo* mPlayerInfo;
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    PlayerTrigger* mPlayerTrigger;
    HackCap* mHackCap;
    ActorDimensionKeeper* mActorDimensionKeeper;
    PlayerModelHolder* mPlayerModelHolder;
    PlayerModelChangerHakoniwa* mPlayerModelChangerHakoniwa;
    PlayerAnimator* mPlayerAnimator;
    PlayerColliderHakoniwa* mPlayerColliderHakoniwa;
    PlayerPuppet* mPlayerPuppet;
    PlayerAreaChecker* mPlayerAreaChecker;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    PlayerOxygen* mPlayerOxygen;
    PlayerDamageKeeper* mPlayerDamageKeeper;
    PlayerDemoActionFlag* mPlayerDemoActionFlag;
    PlayerCapActionHistory* mPlayerCapActionHistory;
    PlayerCapManHeroEyesControl* mPlayerCapManHeroEyesControl;
    PlayerContinuousJump* mPlayerContinuousJump;
    PlayerContinuousLongJump* mPlayerContinuousLongJump;
    PlayerCounterAfterUpperPunch* mPlayerCounterAfterUpperPunch;
    PlayerCounterForceRun* mPlayerCounterForceRun;
    PlayerCounterIceWater* mPlayerCounterIceWater;
    PlayerCounterQuickTurnJump* mPlayerCounterQuickTurnJump;
    PlayerWallActionHistory* mPlayerWallActionHistory;
    PlayerBindKeeper* mPlayerBindKeeper;
    PlayerCarryKeeper* mPlayerCarryKeeper;
    PlayerEquipmentUser* mPlayerEquipmentUser;
    PlayerHackKeeper* mPlayerHackKeeper;
    PlayerFormSensorCollisionArranger* mPlayerFormSensorCollisionArranger;
    PlayerJumpMessageRequest* mPlayerJumpMessageRequest;
    PlayerSandSinkAffect* mPlayerSandSinkAffect;
    PlayerSpinCapAttack* mPlayerSpinCapAttack;
    PlayerActionDiveInWater* mPlayerActionDiveInWater;
    PlayerEffect* mPlayerEffect;
    PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder;
    PlayerPushReceiver* mPlayerPushReceiver;
    PlayerHitPush* mPlayerHitPush;
    PlayerExternalVelocity* mPlayerExternalVelocity;
    PlayerJointControlKeeper* mPlayerJointControlKeeper;
    PlayerPainPartsKeeper* mPlayerPainPartsKeeper;
    PlayerRecoverySafetyPoint* mPlayerRecoverySafetyPoint;
    PlayerRippleGenerator* mPlayerRippleGenerator;
    PlayerSeparateCapFlag* mPlayerSeparateCapFlag;
    PlayerWetControl* mPlayerWetControl;
    PlayerStainControl* mPlayerStainControl;
    al::FootPrintHolder* mFootPrintHolder;
    GaugeAir* mGaugeAir;
    WaterSurfaceShadow* mWaterSurfaceShadow;
    WorldEndBorderKeeper* mWorldEndBorderKeeper;
    void* gap;
    PlayerSeCtrl* mPlayerSeCtrl;
    al::HitSensor* mBodyHitSensor;
    bool mIsLongShadow;
    PlayerStateWait* mPlayerStateWait;
    PlayerStateSquat* mPlayerStateSquat;
    PlayerStateRunHakoniwa2D3D* mPlayerStateRunHakoniwa2D3D;
    PlayerStateSlope* mPlayerStateSlope;
    PlayerStateRolling* mPlayerStateRolling;
    PlayerStateSpinCap* mPlayerStateSpinCap;
    PlayerStateJump* mPlayerStateJump;
    PlayerStateCapCatchPop* mPlayerStateCapCatchPop;
    PlayerStateWallAir* mPlayerStateWallAir;
    PlayerStateWallCatch* mPlayerStateWallCatch;
    PlayerStateGrabCeil* mPlayerStateGrabCeil;
    PlayerStatePoleClimb* mPlayerStatePoleClimb;
    PlayerStateHipDrop* mPlayerStateHipDrop;
    PlayerStateHeadSliding* mPlayerStateHeadSliding;
    PlayerStateLongJump* mPlayerStateLongJump;
    PlayerStateFallHakoniwa* mPlayerStateFallHakoniwa;
    PlayerStateSandSink* mPlayerStateSandSink;
    ActorStateSandGeyser* mActorStateSandGeyser;
    PlayerStateRise* mPlayerStateRise;
    PlayerStateSwim* mPlayerStateSwim;
    PlayerStateDamageLife* mPlayerStateDamageLife;
    PlayerStateDamageSwim* mPlayerStateDamageSwim;
    PlayerStateDamageFire* mPlayerStateDamageFire;
    PlayerStatePress* mPlayerStatePress;
    PlayerStateBind* mPlayerStateBind;
    PlayerStateHack* mPlayerStateHack;
    PlayerStateEndHack* mPlayerStateEndHack;
    PlayerStateCameraSubjective* mPlayerStateCameraSubjective;
    PlayerStateAbyss* mPlayerStateAbyss;
    PlayerJudgeAirForceCount* mPlayerJudgeAirForceCount;
    PlayerJudgeCameraSubjective* mPlayerJudgeCameraSubjective;
    PlayerJudgeCapCatchPop* mPlayerJudgeCapCatchPop;
    PlayerJudgeDeadWipeStart* mPlayerJudgeDeadWipeStart;
    PlayerJudgeDirectRolling* mPlayerJudgeDirectRolling;
    PlayerJudgeEnableStandUp* mPlayerJudgeEnableStandUp;
    PlayerJudgeForceLand* mPlayerJudgeForceLand;
    PlayerJudgeForceSlopeSlide* mPlayerJudgeForceSlopeSlide;
    PlayerJudgeForceRolling* mPlayerJudgeForceRolling;
    PlayerJudgeGrabCeil* mPlayerJudgeGrabCeil;
    PlayerJudgeInWater* mPlayerJudgeInWater1;
    PlayerJudgeInWater* mPlayerJudgeInWater2;
    PlayerJudgeInWater* mPlayerJudgeInWater3;
    PlayerJudgeInWater* mPlayerJudgeInWater4;
    PlayerJudgeInvalidateInputFall* mPlayerJudgeInvalidateInputFall;
    PlayerJudgeLongFall* mPlayerJudgeLongFall;
    PlayerJudgeOutInWater* mPlayerJudgeOutInWater;
    PlayerJudgeRecoveryLifeFast* mPlayerJudgeRecoveryLifeFast;
    PlayerJudgeSandSink* mPlayerJudgeSandSink;
    PlayerJudgeSpeedCheckFall* mPlayerJudgeSpeedCheckFall;
    PlayerJudgeStartHipDrop* mPlayerJudgeStartHipDrop;
    PlayerJudgeStartRise* mPlayerJudgeStartRise;
    PlayerJudgeStartRolling* mPlayerJudgeStartRolling;
    PlayerJudgeStartRun* mPlayerJudgeStartRun;
    PlayerJudgeStartSquat* mPlayerJudgeStartSquat;
    PlayerJudgeStartWaterSurfaceRun* mPlayerJudgeStartWaterSurfaceRun;
    PlayerJudgeSlopeSlide* mPlayerJudgeSlopeSlide;
    PlayerJudgePoleClimb* mPlayerJudgePoleClimb;
    PlayerJudgePreInputJump* mPlayerJudgePreInputJump;
    PlayerJudgePreInputCapThrow* mPlayerJudgePreInputCapThrow;
    PlayerJudgePreInputHackAction* mPlayerJudgePreInputHackAction;
    HackCapJudgePreInputHoveringJump* mHackCapJudgePreInputHoveringJump;
    HackCapJudgePreInputSeparateThrow* mHackCapJudgePreInputSeparateThrow;
    HackCapJudgePreInputSeparateJump* mHackCapJudgePreInputSeparateJump;
    PlayerJudgeWallCatch* mPlayerJudgeWallCatch;
    PlayerJudgeWallCatchInputDir* mPlayerJudgeWallCatchInputDir;
    PlayerJudgeWallHitDown* mPlayerJudgeWallHitDown;
    PlayerJudgeWallHitDownForceRun* mPlayerJudgeWallHitDownForceRun;
    PlayerJudgeWallHitDownRolling* mPlayerJudgeWallHitDownRolling;
    PlayerJudgeWallKeep* mPlayerJudgeWallKeep;
    void* gap_2;
};