#pragma once

#include "types.h"

class PlayerConst { // 0x9A8 i think is PlayerConst's size, which is every single entry plus some extra space for something
    public: // note: these functions are in the order that the addresses are in, so doing a bit of messing around with these declarations should also allow for the full header to be decompiled
        f32 getGravity(void) const;
        f32 getFrictionAttack(void) const;
        f32 getPushPower(void) const;
        f32 getWaitPoseDegreeMax(void) const;
        f32 getHillPoseDegreeMax(void) const;
        f32 getTiltPoseDegreeMax(void) const;
        f32 getSlerpQuatRate(void) const;
        f32 getSlerpQuatRateWait(void) const;
        f32 getSlerpQuatGrav(void) const;
        int getPreInputFrameCapThrow(void) const;
        int getEnableActionFrameCapCatch(void) const;
        f32 getJumpPowerCapCatch(void) const;
        f32 getJumpGravityCapCatch(void) const;
        int getRunTimeContinuousThrow(void) const;
        f32 getRunSpeedMaxContinuousThrow(void) const;
        int getRunAccelFrameContinuousThrow(void) const;
        f32 getSeparateCheckHeight(void) const;
        f32 getSeparateOffsetLerpRate(void) const;
        f32 getSeparateEnableThrowHeight(void) const;
        f32 getTall(void) const;
        f32 getCollisionRadius(void) const;
        f32 getCollisionRadiusSquat(void) const;
        f32 getCollisionRadiusStand(void) const;
        f32 getCollisionSmallStepHeight(void) const;
        f32 getCollisionResetLimit(void) const;
        f32 getReflectCeilingPower(void) const;
        f32 getReflectTossPower(void) const;
        f32 getReflectUpperPunchScaleH(void) const;
        f32 getCollisionHitDownAngleH(void) const;
        f32 getCollisionHitDownEscapeAngleV(void) const;
        f32 getShadowDropHeightScale(void) const;
        f32 getShadowDropNormalAdd(void) const;
        f32 getShadowDropLengthMin(void) const;
        f32 getShadowDropLengthMax(void) const;
        f32 getShadowDropLengthExtend(void) const;
        f32 getGravityDamage(void) const;
        f32 getHopPowerDamage(void) const;
        f32 getPushPowerDamage(void) const;
        int getDamageCancelFrame(void) const;
        int getDamageInvalidCount(void) const;
        int getDamageInvalidCountRecovery(void) const;
        int getDamageInvalidCountAbyss(void) const;
        f32 getNormalMinSpeed2D(void) const;
        f32 getNormalMaxSpeed2D(void) const;
        f32 getDashMaxSpeed2D(void) const;
        int getNormalAccelFrame2D(void) const;
        int getDashAccelFrame2D(void) const;
        int getNormalDashAnimFrame2D(void) const;
        int getNormalBrakeFrame2D(void) const;
        int getStickOnBrakeFrame2D(void) const;
        int getBrakeTurnStartFrame2D(void) const;
        f32 getTurnEndSpeedRate2D(void) const;
        f32 getJumpPowerMin2DArea(void) const;
        f32 getJumpPowerMax2DArea(void) const;
        f32 getJumpPowerMinBorder2D(void) const;
        f32 getJumpPowerMaxBorder2D(void) const;
        f32 getGravityMove(void) const;
        f32 getNormalMaxSpeed(void) const;
        f32 getNormalMinSpeed(void) const;
        int getNormalAccelFrame(void) const;
        f32 getRunAccelAverageScale(void) const;
        int getNormalBrakeFram(void) const;
        f32 getDashJudgeSpeed(void) const;
        int getStickOnBrakeFrame(void) const;
        int getNormalDashAnimFrame(void) const;
        f32 getRunAfterTurnSpeedMax(void) const;
        f32 getRunAfterTurnScale(void) const;
        int getRunAfterTurnFrame(void) const;
        int getBrakeTurnStartFrame(void) const;
        f32 getBrakeOnSpeedRate(void) const;
        int getBrakeOnCounterBorder(void) const;
        int getWallPushFrame(void) const;
        int getRunDeepDownFrame(void) const;
        int getRunDeepDownMargine(void) const;
        int getQuickTurnJumpFrame(void) const;
        int getRoundAccelFrame(void) const;
        int getRoundBrakeFrame(void) const;
        f32 getRoundFastDegree(void) const;
        int getRoundAccelFrameFast(void) const;
        f32 getRoundMinDegree(void) const;
        int getRoundBrakeFrameForce(void) const;
        f32 getRoundFastDegreeForce(void) const;
        f32 getRoundLimitDegreeForce(void) const;
        f32 getRoundLimitDegreeForceFast(void) const;
        int getRoundAccelFrameForceFast(void) const;
        f32 getRoundLimitDegreeMin(void) const;
        f32 getRoundLimitDegree(void) const;
        int getIceAccelFrame(void) const;
        int getIceBrakeFrame(void) const;
        int getIceBrakeFrameHigh(void) const;
        int getIceBrakeFrameWall(void) const;
        int getIceRoundAccelFrame(void) const;
        int getIceRoundAccelFrameFast(void) const;
        int getIceRoundBrakeFrame(void) const;
        f32 getIceRoundFastDegree(void) const;
        f32 getIceRoundMinDegree(void) const;
        f32 getIceRoundLimitDegree(void) const;
        f32 getHillAddSpeed(void) const;
        f32 getHillSubSpeed(void) const;
        int getHillAccelAddFrame(void) const;
        int getHillAccelSubFrame(void) const;
        f32 getHillAccelSubAngleMin(void) const;
        f32 getHillAccelSubAngleMax(void) const;
        f32 getStandAngleMin(void) const;
        f32 getStandAngleMax(void) const;
        f32 getHillAngleSpeedMin(void) const;
        f32 getHillAngleSpeedMax(void) const;
        int getSpinCapThrowFrame(void) const;
        int getSpinCapThrowFrameAir(void) const;
        int getSpinCapThrowFrameSwim(void) const;
        int getSpinCapThrowFrameSwing(void) const;
        int getSpinCapThrowFrameContinuous(void) const;
        int getSpinAttackFrame(void) const;
        int getSpinBrakeFrame(void) const;
        f32 getSpinAirJumpPower(void) const;
        f32 getSpinAirSpeedMax(void) const;
        f32 getGravitySpinAir(void) const;
        f32 getSlerpQuatRateSpinAir(void) const;
        f32 getSpinBrakeRate(void) const;
        f32 getSpinBrakeSideAccel(void) const;
        f32 getSpinBrakeSideBrakeRate(void) const;
        f32 getSpinBrakeSideMaxSpeedRate(void) const;
        f32 getSpinRoundLimitDegree(void) const;
        f32 getDamageFireJumpPower1st(void) const;
        f32 getDamageFireJumpPower2nd(void) const;
        f32 getDamageFireJumpMoveSpeed(void) const;
        f32 getDamageFireCeilHitSpeed(void) const;
        f32 getDamageFireGravity(void) const;
        int getDamageFireNoGravityFrame(void) const;
        int getDamageFireRunTime(void) const;
        f32 getDamageFireRunSpeed(void) const;
        f32 getDamageFireRunBrakeFrame(void) const;
        int getSandSinkDeadTime(void) const;
        int getSandSinkBrakeHeightH(void) const;
        int getSandSinkBrakeHeightV(void) const;
        f32 getSandSinkHeight(void) const;
        f32 getSandSinkCapThrow(void) const;
        f32 getSandSinkBrakeMinH(void) const;
        f32 getSandSinkBrakeMaxH(void) const;
        f32 getSandSinkBrakeMinV(void) const;
        f32 getSandSinkBrakeMaxV(void) const;
        f32 getSlopeSlideAngleStart(void) const;
        f32 getSlopeSlideAngleEnd(void) const;
        f32 getSlopeSlideAccel(void) const;
        f32 getSlopeSlideBrake(void) const;
        f32 getSlopeSlideMaxSpeed(void) const;
        f32 getSlopeSlideSpeedEnd(void) const;
        f32 getSlopeSlideSideAccel(void) const;
        f32 getSlopeSlideSideBrake(void) const;
        f32 getSlopeSlideSideMaxSpeed(void) const;
        f32 getSlopeTurnDegree(void) const;
        int getSlideInvalidFrame(void) const;
        int getSlopeForceFrame(void) const;
        f32 getSlopeSlideForceSideAccel(void) const;
        f32 getSlopeSlideForceSideBrake(void) const;
        f32 getSlopeSlideForceSideMaxSpeed(void) const;
        f32 getSlopeSlideForceTurnDegree(void) const;
        f32 getSlopeRollingSpeedStart(void) const;
        f32 getSlopeRollingSpeedBoost(void) const;
        f32 getSlopeRollingMaxSpeed(void) const;
        int getSlopeRollingFrameMinBoost(void) const;
        int getSlopeRollingFrameMin(void) const;
        f32 getSlopeRollingStartJumpPower(void) const;
        f32 getSlopeRollingStartSlideSpeed(void) const;
        f32 getSlopeRollingAccel(void) const;
        f32 getSlopeRollingBrake(void) const;
        f32 getSlopeRollingAgainst(void) const;
        f32 getSlopeRollingAnglePowerMax(void) const;
        f32 getSlopeRollingSpeedEnd(void) const;
        f32 getSlopeRollingSideAccel(void) const;
        f32 getSlopeRollingSideBrake(void) const;
        f32 getSlopeRollingSideMaxSpeed(void) const;
        int getSlopeRollingUnRollFrame(void) const;
        f32 getSlopeRollingEndBrake(void) const;
        f32 getSlopeRollingEndBrakeEndSpeed(void) const;
        f32 getSlopeRollingReStartAccel(void) const;
        f32 getSlopeRollingReStartMaxAdd(void) const;
        int getSlopeRollingReStarterval(void) const;
        int getSlopeRollingReStartSwing(void) const;
        int getSlopeRollingReStartCharge(void) const;
        int getSlopeRollingReStartForce(void) const;
        f32 getSlopeRollingAccelOnSkate(void) const;
        f32 getSlopeRollingSideAccelOnSkate(void) const;
        f32 getSlopeRollingBrakeOnSkate(void) const;
        int getExtendFrame(void) const;
        f32 getJumpInertiaRate(void) const;
        f32 getJumpPowerMin(void) const;
        f32 getJumpPowerMax(void) const;
        f32 getJumpGravity(void) const;
        f32 getJumpBaseSpeedMax(void) const;
        f32 getJumpMoveSpeedMin(void) const;
        f32 getJumpMoveSpeedMax(void) const;
        f32 getJumpAccelFront(void) const;
        f32 getJumpAccelBack(void) const;
        f32 getJumpAccelTurn(void) const;
        f32 getJumpTurnAngleStart(void) const;
        f32 getJumpTurnAngleLimit(void) const;
        f32 getJumpTurnAngleFast(void) const;
        f32 getJumpTurnAngleFastLimit(void) const;
        int getJumpTurnAccelFrame(void) const;
        int getJumpTurnAccelFrameFast(void) const;
        int getJumpTurnBrakeFrame(void) const;
        f32 getTrampleGravity(void) const;
        f32 getTrampleJumpPower(void) const;
        f32 getTrampleHighGravity(void) const;
        f32 getTrampleHighJumpPower(void) const;
        f32 getTrampleGravity2D(void) const;
        f32 getTrampleJumpPower2D(void) const;
        f32 getTrampleHighGravity2D(void) const;
        f32 getTrampleHighJumpPower2D(void) const;
        f32 getTrampleHipDropGravity(void) const;
        f32 getTrampleHipDropJumpPower(void) const;
        f32 getTrampleRisingBrakeVelH(void) const;
        f32 getTrampleJumpCodePower(void) const;
        f32 getTrampleJumpCodePowerSmall(void) const;
        f32 getCapLeapFrogJumpGravity(void) const;
        f32 getCapLeapFrogJumpPower(void) const;
        f32 getCapLeapFrogJumpPowerAir(void) const;
        f32 getObjLeapFrogJumpPower(void) const;
        f32 getObjLeapFrogJumpPowerHigh(void) const;
        f32 getCapHeadSpringJumpGravity(void) const;
        f32 getCapHeadSpringJumpPower(void) const;
        f32 getCapHeadSpringJumpGravityHigh(void) const;
        f32 getCapHeadSpringJumpPowerHigh(void) const;
        f32 getCapHeadSpringSpeedMax(void) const;
        int getContinuousJumpPreInputFrame(void) const;
        int getContinuousJumpCount(void) const;
        int getContinuousJumpTimer(void) const;
        f32 getContinuousJumpPowerMin(void) const;
        f32 getJumpPowerMax2nd(void) const;
        f32 getJumpGravity2nd(void) const;
        f32 getJumpPowerMax3rd(void) const;
        f32 getJumpGravity3rd(void) const;
        f32 getSpinFlowerJumpGravity(void) const;
        f32 getSpinFlowerJumpFallSpeedMax(void) const;
        f32 getSpinFlowerJumpMovePower(void) const;
        f32 getSpinFlowerJumpVelMax(void) const;
        int getSpinFlowerJumpStayFrame(void) const;
        f32 getSpinFlowerJumpStaySpeedMax(void) const;
        f32 getSpinFlowerJumpNoInputBrake(void) const;
        f32 getSpinFlowerJumpDownFallInitSpeed(void) const;
        f32 getSpinFlowerJumpDownFallPower(void) const;
        f32 getSpinFlowerJumpDownFallSpeedMax(void) const;
        f32 getJumpGravityForceRun(void) const;
        f32 getJumpPowerForceRun(void) const;
        f32 getCapCatchPopPower(void) const;
        f32 getCapCatchPopGravity(void) const;
        f32 getSquatJumpGravity(void) const;
        f32 getSquatJumpPower(void) const;
        f32 getSquatJumpBackPower(void) const;
        f32 getSquatJumpMovePowerFront(void) const;
        f32 getSquatJumpMovePowerSide(void) const;
        f32 getSquatJumpMoveSpeedMax(void) const;
        f32 getTurnJumpGravity(void) const;
        f32 getTurnJumpPower(void) const;
        f32 getTurnJumpVelH(void) const;
        f32 getTurnJumpBrake(void) const;
        f32 getTurnJumpAccel(void) const;
        f32 getTurnJumpSideAccel(void) const;
        f32 getLongJumpAccel(void) const;
        f32 getLongJumpBrake(void) const;
        f32 getLongJumpSideAccel(void) const;
        f32 getLongJumpGravity(void) const;
        f32 getLongJumpJumpPow(void) const;
        f32 getLongJumpMovePow(void) const;
        f32 getLongJumpInitSpeed(void) const;
        f32 getLongJumpSpeed(void) const;
        f32 getLongJumpSpeedMin(void) const;
        int getContinuousLongJumpCount(void) const;
        int getContinuousLongJumpTimer(void) const;
        f32 getGravityAir(void) const;
        f32 getFrictionAir(void) const;
        f32 getFallSpeedMax(void) const;
        f32 getLongFallDistance(void) const;
        f32 getFallWallScaleVelocity(void) const;
        int getDownFallFrameMin(void) const;
        f32 getGravityWallSlide(void) const;
        f32 getWallHeightLowLimit(void) const;
        f32 getWallKeepDegree(void) const;
        int getWallKeepFrame(void) const;
        f32 getWallJumpGravity(void) const;
        f32 getWallJumpHSpeed(void) const;
        f32 getWallJumpPower(void) const;
        int getWallJumpInvalidateInputFrame(void) const;
        int getWallInhibitAfterPunch(void) const;
        f32 getWallFollowAngleH(void) const;
        f32 getWallFollowAngleV(void) const;
        f32 getWallCatchDegree(void) const;
        f32 getWallCatchHeightEdgeTop(void) const;
        f32 getWallCatchHeightBottom(void) const;
        f32 getWallCatchKeepDegree(void) const;
        f32 getWallCatchMoveDegree(void) const;
        f32 getWallCatchMoveSpeed(void) const;
        f32 getWallCatchMoveHeightRange(void) const;
        int getWallCatchMoveerpolate(void) const;
        int getWallCatchMoveFrame(void) const;
        int getWallCatchMoveFrameFast(void) const;
        int getWallCatchMoveFrameSwing(void) const;
        f32 getWallCatchInputRepeatAngle(void) const;
        f32 getWallClimbDegree(void) const;
        int getWallClimbJumpStartFrame(void) const;
        int getWallClimbJumpEndFrame(void) const;
        int getWallClimbStartFrame(void) const;
        f32 getWallClimbGravity(void) const;
        f32 getWallFallJumpSpeed(void) const;
        f32 getWallClimbJumpSpeedV(void) const;
        f32 getWallClimbJumpSpeedH(void) const;
        f32 getWallClimbJumpGravity(void) const;
        int getWallClimbJumpInvalidFrame(void) const;
        f32 getWallCatchHipLocalOffset(void) const;
        f32 getWallCatchHipStability(void) const;
        f32 getWallCatchHipFriction(void) const;
        f32 getWallCatchHipLimitDegree(void) const;
        f32 getWallCatchStainAreaOffset(void) const;
        f32 getGrabCeilRange(void) const;
        f32 getGrabCeilBodyRadius(void) const;
        f32 getGrabCeilLeaveSpeedMin(void) const;
        f32 getGrabCeilLeavePopPower(void) const;
        f32 getGrabCeilLeavePopGravity(void) const;
        f32 getGrabCeilSwingStartOffset(void) const;
        f32 getGrabCeilReverseInputBorder(void) const;
        f32 getGrabCeilInputPowerBorder(void) const;
        f32 getGrabCeilSwingWaitEnergy(void) const;
        f32 getGrabCeilEnableJumpEnergy(void) const;
        f32 getGrabCeilEnableJumpEnergyMax(void) const;
        f32 getGrabCeilJumpForceAngle(void) const;
        f32 getGrabCeilJumpPower(void) const;
        f32 getGrabCeilJumpMoveMin(void) const;
        f32 getGrabCeilJumpMoveMax(void) const;
        f32 getGrabCeilJumpGravity(void) const;
        int getGrabCeilJumpInvalidFrame(void) const;
        int getGrabCeilEnableNextFrame(void) const;
        int getGrabCeilEnableFallSnapFrame(void) const;
        int getPoleClimbPreInputSwing(void) const;
        f32 getPoleClimbInputRepeatAngle(void) const;
        f32 getPoleClimbInputDegreeMove(void) const;
        f32 getPoleClimbCatchRange(void) const;
        f32 getPoleClimbCatchRangeMin(void) const;
        f32 getPoleClimbCatchRangeMax(void) const;
        f32 getPoleClimbJointAngleMin(void) const;
        f32 getPoleClimbJointAngleMax(void) const;
        f32 getPoleClimbJointRangeMin(void) const;
        f32 getPoleClimbJointRangeMax(void) const;
        f32 getPoleClimbMoveWallDegree(void) const;
        f32 getPoleClimbUpMargine(void) const;
        f32 getPoleClimbUpSpeed(void) const;
        int getPoleClimbUpFrame(void) const;
        int getPoleClimbUpFrameFast(void) const;
        int getPoleClimbUpFrameSwing(void) const;
        f32 getPoleClimbDownSpeed(void) const;
        f32 getPoleClimbDownSpeedFast(void) const;
        f32 getPoleClimbDownSpeedSwing(void) const;
        int getPoleClimbDownFrame(void) const;
        int getPoleClimbDownKeepTime(void) const;
        f32 getPoleClimbTurnDist(void) const;
        int getPoleClimbTurnFrame(void) const;
        int getPoleClimbTurnStopFrame(void) const;
        int getPoleTopStartFrame(void) const;
        int getPoleTopEndFrame(void) const;
        f32 getPoleTopTurnSpeed(void) const;
        f32 getPoleTopEndUnderOffsetY(void) const;
        int getGroundSpinFrame(void) const;
        f32 getGroundSpinMoveSpeedMax(void) const;
        f32 getGroundSpinAccelRate(void) const;
        f32 getGroundSpinBrakeRate(void) const;
        f32 getSpinJumpGravity(void) const;
        f32 getSpinJumpPower(void) const;
        f32 getSpinJumpMoveSpeedMax(void) const;
        f32 getSpinJumpDownFallInitSpeed(void) const;
        f32 getSpinJumpDownFallPower(void) const;
        f32 getSpinJumpDownFallSpeedMax(void) const;
        f32 getSquatBrakeEndSpeed(void) const;
        f32 getSquatAccelRate(void) const;
        f32 getSquatBrakeRate(void) const;
        f32 getSquatBrakeRateOnSkate(void) const;
        f32 getSquatBrakeSideAccel(void) const;
        f32 getSquatBrakeSideRate(void) const;
        f32 getSquatBrakeSideAccelOnSkate(void) const;
        f32 getSquatBrakeSideRateOnSkate(void) const;
        f32 getSquatBrakeSideMaxSpeedRate(void) const;
        f32 getSquatWalkSpeed(void) const;
        f32 getSquatWalkTurnSpeed(void) const;
        int getSquatWalkTurnFrame(void) const;
        f32 getSquatJumpCeilSlideSpeed2D(void) const;
        f32 getHipDropSpeed(void) const;
        f32 getHipDropGravity(void) const;
        f32 getHipDropSpeedMax(void) const;
        int getHipDropLandCancelFrame(void) const;
        f32 getHipDropHeight(void) const;
        int getHipDropMsgerval(void) const;
        f32 getJumpHipDropPower(void) const;
        int getJumpHipDropPermitBeginFrame(void) const;
        int getJumpHipDropPermitEndFrame(void) const;
        f32 getHeadSlidingSpeed(void) const;
        f32 getHeadSlidingSpeedMin(void) const;
        f32 getHeadSlidingBrake(void) const;
        f32 getHeadSlidingSideAccel(void) const;
        f32 getHeadSlidingJump(void) const;
        f32 getHeadSlidingGravityAir(void) const;
        f32 getSwimCenterOffset(void) const;
        f32 getSwimWallCatchOffset(void) const;
        f32 getSwimRisePower(void) const;
        f32 getSwimRiseSpeedMax(void) const;
        int getSwimRiseFrame(void) const;
        f32 getSwimGravity(void) const;
        f32 getSwimGravityWalk(void) const;
        f32 getSwimFallSpeedMax(void) const;
        f32 getSwimFloorAccelH(void) const;
        f32 getSwimFloorSpeedMaxH(void) const;
        f32 getSwimHighAccelH(void) const;
        f32 getSwimHighSpeedMaxH(void) const;
        f32 getSwimLowAccelH(void) const;
        f32 getSwimLowSpeedMaxH(void) const;
        f32 getSwimBrakeRateH(void) const;
        f32 getSwimWallHitSpeedMinH(void) const;
        int getSwimHighAccelPermitFrame(void) const;
        f32 getSwimFlowFieldBlend(void) const;
        f32 getSwimWalkAnimMinRate(void) const;
        f32 getSwimWalkAnimMaxRate(void) const;
        f32 getSwimWalkMaxSpeed(void) const;
        f32 getSwimSpinCapUpPower(void) const;
        f32 getSwimSpinCapUpSpeedMax(void) const;
        f32 getSwimRotStartAngle(void) const;
        f32 getSwimRotFastAngle(void) const;
        int getSwimRotAccelFrame(void) const;
        int getSwimRotAccelFrameFast(void) const;
        int getSwimRotBrakeFrame(void) const;
        f32 getSwimRotSpeedChangeStart(void) const;
        f32 getSwimRotSpeedForward(void) const;
        f32 getSwimRotSpeedMax(void) const;
        f32 getSwimSurfaceAccelH(void) const;
        f32 getSwimSurfaceSpeedMaxH(void) const;
        int getSwimSurfaceSpinCapFrame(void) const;
        f32 getSwimSurfaceSpinCapSpeedMaxH(void) const;
        f32 getSwimSurfaceStartDist(void) const;
        f32 getSwimSurfaceEndDist(void) const;
        f32 getSwimSurfaceGravity(void) const;
        f32 getSwimSurfaceBaseHeight(void) const;
        f32 getSwimSurfaceSpring(void) const;
        f32 getSwimSurfaceDamper(void) const;
        int getSwimSurfaceDamperStart(void) const;
        int getSwimSurfaceDamperFrame(void) const;
        f32 getSwimSurfaceEnableJumpHeight(void) const;
        int getSwimSurfacePreInputJumpFrame(void) const;
        f32 getSwimSurfaceMoveSpring(void) const;
        f32 getSwimSurfaceMoveDamper(void) const;
        f32 getSwimSurfaceMoveBaseHeight(void) const;
        f32 getSwimRunSurfaceBaseHeight(void) const;
        f32 getSwimRunSurfaceApproachRate(void) const;
        f32 getSwimRunSurfaceApproachLimit(void) const;
        f32 getSwimRunSurfaceBrakeBorder(void) const;
        f32 getSwimRunSurfaceBrakeH(void) const;
        f32 getSwimRunSurfaceApproachBorderMax(void) const;
        f32 getSwimRunSurfaceApproachBorderMin(void) const;
        f32 getSwimRunSurfaceApproachRateMin(void) const;
        f32 getSwimFallInSpeed(void) const;
        f32 getSwimFallInBrakeH(void) const;
        f32 getSwimFallInBrakeV(void) const;
        f32 getSwimHeadInBrakeH(void) const;
        f32 getSwimHeadInBrakeV(void) const;
        f32 getSwimHeadInRisePower(void) const;
        f32 getSwimHeadInRiseSpeedMax(void) const;
        f32 getSwimHeadInSurfaceHeight(void) const;
        int getSwimFallInForceSurfaceFrame(void) const;
        int getSwimFallInvalidJumpFrame(void) const;
        f32 getSwimDiveStartSpeed(void) const;
        f32 getSwimDiveBrake(void) const;
        f32 getSwimDiveEndSpeed(void) const;
        int getSwimDiveLandCount(void) const;
        int getSwimDiveLandCancelFrame(void) const;
        int getSwimDiveNoBrakeFrame(void) const;
        int getSwimDiveButtonValidFrame(void) const;
        int getSwimDiveEndFrame(void) const;
        f32 getSwimDiveInBrakeH(void) const;
        f32 getSwimDiveInBrakeV(void) const;
        f32 getSwimDiveInRisePower(void) const;
        f32 getSwimDiveInRiseSpeedMax(void) const;
        f32 getSwimDiveInSurfaceHeight(void) const;
        int getSwimDiveInKeepFrame(void) const;
        int getSwimHeadSlidingFrame(void) const;
        int getSwimHeadSlidingBrakeFrame(void) const;
        f32 getSwimHeadSlidingSpeed(void) const;
        f32 getSwimHeadSlidingSpeedEnd(void) const;
        f32 getSwimHeadSlidingBrake(void) const;
        f32 getSwimHeadSlidingSideAccel(void) const;
        f32 getSwimHeadSlidingJump(void) const;
        f32 getSwimHeadSlidingGravity(void) const;
        int getSwimHeadSlidingEndBrakeFrame(void) const;
        int getSwimHeadSlidingEndSpeedMin(void) const;
        f32 getSwimJumpHipDropSpeed(void) const;
        f32 getSwimJumpHipDropBrakeV(void) const;
        f32 getSwimJumpHipDropBrakeVCeiling(void) const;
        f32 getSwimJumpHipDropGravity(void) const;
        f32 getSwimJumpHipDropCancelSpeed(void) const;
        f32 getSwimJumpHipDropAccelH(void) const;
        f32 getSwimJumpHipDropMoveSpeedH(void) const;
        f32 getSwimJumpHipDropPopSpeed(void) const;
        f32 getSwimJumpHipDropPopJumpAdd(void) const;
        f32 getSwimTramplePower(void) const;
        f32 getDiveTramplePower(void) const;
        int getDiveTrampleCancelFrame(void) const;
        f32 getDamageSwimPushPower(void) const;
        f32 getDamageSwimGravity(void) const;
        int getDamageSwimCancelFrame(void) const;
        f32 getDamageSwimSurfaceGravity(void) const;
        f32 getDamageSwimSurfaceHopPower(void) const;
        f32 getDamageSwimSurfacePushPower(void) const;
        f32 getDamageSwimSurfaceLandSpeed(void) const;
        f32 getDamageSwimSurfaceLandBrake(void) const;
        f32 getDamageSwimSurfaceLandEndSpeed(void) const;
        int getDamageSwimSurfaceCancelFrame(void) const;
        f32 getDamageSwimBrakeRateGround(void) const;
        int getOxygenReduceFrame(void) const;
        int getOxygenNoReduceFrame(void) const;
        int getOxygenRecoveryFrame(void) const;
        int getOxygenDamageerval(void) const;
        int getIceWaterDamageerval(void) const;
        int getIceWaterRecoveryFrame(void) const;
        f32 getMoveAnimSpeedMax(void) const;
        f32 getAnimFrameRateSpeedMin(void) const;
        f32 getRunBorderSpeed(void) const;
        f32 getRunBlendRange(void) const;
        f32 getDashBorderSpeed(void) const;
        f32 getDashBlendRange(void) const;
        f32 getDashFastBorderSpeed(void) const;
        f32 getDashFastBlendRange(void) const;
        f32 getAnimFrameRateSpeedMax(void) const;
        f32 getAnimFrameRateRunStart(void) const;
        f32 getAnimFrameRateMinRun(void) const;
        f32 getAnimFrameRateMaxRun(void) const;
        f32 getAnimFrameRateMaxDash(void) const;
        f32 getAnimFrameRateMaxDashFast(void) const;
        f32 getRunStartPlayFrameScale(void) const;
        int getRunStartBlendFrame(void) const;
        f32 getDamageFireRunAnimRate(void) const;
        f32 getRunSkateAnimSpeedOffset(void) const;
        f32 getAnimFrameRateRange2D(void) const;
        f32 getAnimFrameRateMinRun2D(void) const;
        f32 getAnimFrameRateMaxRun2D(void) const;
        int getIKBlendFrameRun(void) const;
        f32 getIKBlendRateRunMin(void) const;
        f32 getIKBlendRateRunMax(void) const;
        f32 getRollingAnimBorderSpeedMin(void) const;
        f32 getRollingAnimBorderSpeedMax(void) const;
        f32 getRollingAnimFrameRateMin(void) const;
        f32 getRollingAnimFrameRateMax(void) const;
        int getSwimPaddleAnimerval(void) const;
        int getSwimPaddleAnimRateervalMax(void) const;
        int getSwimPaddleAnimRateervalMin(void) const;
        f32 getSwimPaddleAnimMaxRate(void) const;
        f32 getSwimBentForwardMax(void) const;
        f32 getSwimBentForwardBlendRate(void) const;
        f32 getSwimBentSideMax(void) const;
        f32 getSwimBentSpineMax(void) const;
        f32 getSwimBentSideBlendRate(void) const;
        f32 getSwimBentFrontMax(void) const;
        f32 getSwimBentFrontBlendRate(void) const;
        f32 getSwimWalkAnimSpeedMax(void) const;
        f32 getSwimWalkAnimSpeedMin(void) const;
        f32 getSwimWalkAnimFrameRateMax(void) const;
        f32 getSwimWalkAnimFrameRateMin(void) const;
        f32 getSandSinkBorderMin(void) const;
        f32 getSandSinkBorderMax(void) const;
        f32 getSandSinkBorderRateMin(void) const;
        f32 getSandSinkBorderRateMax(void) const;
        f32 getSandSinkFrameRateMin(void) const;
        f32 getSandSinkFrameRateMax(void) const;
        int getLookAtEyeKeepFrame(void) const;
        int getLookAtEyeKeepFrameInSight(void) const;
        int getLookAtEyeKeepFrameWait(void) const;
        f32 getLookAtEyeDistance(void) const;
        f32 getLookAtEyeAngleMinH(void) const;
        f32 getLookAtEyeAngleMinInSightH(void) const;
        f32 getLookAtEyeAngleMaxH(void) const;
        f32 getLookAtEyeAngleMinV(void) const;
        f32 getLookAtEyeAngleMinInSightV(void) const;
        f32 getLookAtEyeAngleMaxV(void) const;
        f32 getTiltEyeBorderStart(void) const;
        f32 getTiltEyeBorderEnd(void) const;
        f32 getTiltEyeAngleScale(void) const;
        f32 getCenterTiltRateMax(void) const;
        f32 getNoseChildLocalOffset(void) const;
        f32 getNoseStability(void) const;
        f32 getNoseFriction(void) const;
        f32 getNoseLimitDegree(void) const;
        f32 getMustacheChildLocalOffset(void) const;
        f32 getMustacheStability(void) const;
        f32 getMustacheFriction(void) const;
        f32 getMustacheLimitDegree(void) const;
        int getCaperpolateFrame(void) const;
        f32 getCapChildLocalOffset(void) const;
        f32 getCapStability(void) const;
        f32 getCapFriction(void) const;
        f32 getCapLimitDegree(void) const;
        f32 getCapTransStability(void) const;
        f32 getCapTransFriction(void) const;
        f32 getCapTransLimit(void) const;
        int getCapManHeroEyesWaitAppearFrame(void) const;
        int getDeadWipeStartDamage(void) const;
        int getDeadWipeWaitDamage(void) const;
        int getDeadWipeStartAbyss(void) const;
        int getDeadWipeWaitAbyss(void) const;
        int getDeadWipeStartAbyssWithCapMsg(void) const;
        int getDeadWipeWaitAbyssWithCapMsg(void) const;
        int getDeadWipeStartPress(void) const;
        int getDeadWipeWaitPress(void) const;
        int getDeadWipeStartSandSink(void) const;
        int getDeadWipeWaitSandSink(void) const;
};