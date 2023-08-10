#pragma once

#include <gfx/seadCamera.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {
class CameraPoser;
class CameraStartInfo;
class CameraObjectRequestInfo;
class IUseCollision;
class PlacementInfo;
}  // namespace al

namespace alCameraPoserFunction {
class CameraCollisionHitResult;

void getViewIndex(const al::CameraPoser*);
void getLookAtCamera(const al::CameraPoser*);
void getProjectionSead(const al::CameraPoser*);
void getProjection(const al::CameraPoser*);
void getProjectionMtx(const al::CameraPoser*);
float getNear(const al::CameraPoser*);
float getFar(const al::CameraPoser*);
float getAspect(const al::CameraPoser*);
void getPreCameraPos(const al::CameraPoser*);
sead::Vector3f& getPreLookAtPos(const al::CameraPoser*);
void getPreUpDir(const al::CameraPoser*);
void getPreFovyDegree(const al::CameraPoser*);
void getPreFovyRadian(const al::CameraPoser*);
bool isPrePriorityDemo(const al::CameraStartInfo&);
bool isPrePriorityDemo2(const al::CameraStartInfo&);
bool isPrePriorityDemoTalk(const al::CameraStartInfo&);
bool isPrePriorityDemoAll(const al::CameraStartInfo&);
bool isPrePriorityEntranceAll(const al::CameraStartInfo&);
bool isPrePriorityPlayer(const al::CameraStartInfo&);
bool isEqualPreCameraName(const al::CameraStartInfo&, const char*);
bool isPreCameraFixAbsolute(const al::CameraStartInfo&);
bool isInvalidCollidePreCamera(const al::CameraStartInfo&);
bool isInvalidKeepPreCameraDistance(const al::CameraStartInfo&);
bool isInvalidKeepPreCameraDistanceIfNoCollide(const al::CameraStartInfo&);
bool isValidResetPreCameraPose(const al::CameraStartInfo&);
bool isValidKeepPreSelfCameraPose(const al::CameraStartInfo&);
void getPreCameraSwingAngleH(const al::CameraStartInfo&);
void getPreCameraSwingAngleV(const al::CameraStartInfo&);
void getPreCameraMaxSwingAngleH(const al::CameraStartInfo&);
void getPreCameraMaxSwingAngleV(const al::CameraStartInfo&);
bool isExistAreaAngleH(const al::CameraStartInfo&);
bool isExistAreaAngleV(const al::CameraStartInfo&);
void getAreaAngleH(const al::CameraStartInfo&);
void getAreaAngleV(const al::CameraStartInfo&);
bool isExistNextPoseByPreCamera(const al::CameraStartInfo&);
void getNextAngleHByPreCamera(const al::CameraStartInfo&);
void getNextAngleVByPreCamera(const al::CameraStartInfo&);
void calcCameraPose(sead::Quat<float>*, const al::CameraPoser*);
void calcLookDir(sead::Vector3f*, const al::CameraPoser*);
void calcCameraDir(sead::Vector3f*, const al::CameraPoser*);
void calcCameraDirH(sead::Vector3f*, const al::CameraPoser*);
void calcLookDirH(sead::Vector3f*, const al::CameraPoser*);
void calcSideDir(sead::Vector3f*, const al::CameraPoser*);
void calcPreCameraDir(sead::Vector3f*, const al::CameraPoser*);
void calcPreCameraDirH(sead::Vector3f*, const al::CameraPoser*);
void calcPreLookDir(sead::Vector3f*, const al::CameraPoser*);
void calcPreLookDirH(sead::Vector3f*, const al::CameraPoser*);
void calcPreCameraAngleH(const al::CameraPoser*);
void calcPreCameraAngleV(const al::CameraPoser*);
void setLookAtPosToTarget(al::CameraPoser*);
void calcTargetTrans(sead::Vector3f*, const al::CameraPoser*);
void setLookAtPosToTargetAddOffset(al::CameraPoser*, const sead::Vector3f&);
void setCameraPosToTarget(al::CameraPoser*);
void setCameraPosToTargetAddOffset(al::CameraPoser*, const sead::Vector3f&);
void calcTargetTransWithOffset(sead::Vector3f*, const al::CameraPoser*);
void calcTargetVelocity(sead::Vector3f*, const al::CameraPoser*);
void calcTargetVelocityH(sead::Vector3f*, const al::CameraPoser*);
void calcTargetUp(sead::Vector3f*, const al::CameraPoser*);
void calcTargetSpeedV(const al::CameraPoser*);
void calcTargetPose(sead::Quat<float>*, const al::CameraPoser*);
void calcTargetFront(sead::Vector3f*, const al::CameraPoser*);
void calcTargetSide(sead::Vector3f*, const al::CameraPoser*);
void calcTargetGravity(sead::Vector3f*, const al::CameraPoser*);
void calcTargetSpeedH(const al::CameraPoser*);
void calcTargetJumpSpeed(const al::CameraPoser*);
void calcTargetFallSpeed(const al::CameraPoser*);
bool isChangeTarget(const al::CameraPoser*);
bool tryGetTargetRequestDistance(float*, const al::CameraPoser*);
bool tryGetBossDistanceCurve(const al::CameraPoser*);
bool tryGetEquipmentDistanceCurve(const al::CameraPoser*);
bool isExistCollisionUnderTarget(const al::CameraPoser*);
void getUnderTargetCollisionPos(const al::CameraPoser*);
void getUnderTargetCollisionNormal(const al::CameraPoser*);
bool isExistSlopeCollisionUnderTarget(const al::CameraPoser*);
bool isExistWallCollisionUnderTarget(const al::CameraPoser*);
bool tryCalcSlopeCollisionDownFrontDirH(sead::Vector3f*, const al::CameraPoser*);
void getSlopeCollisionUpSpeed(const al::CameraPoser*);
void getSlopeCollisionDownSpeed(const al::CameraPoser*);
bool isExistSubTarget(const al::CameraPoser*);
void checkValidTurnToSubTarget(const al::CameraPoser*);
void calcSubTargetBack(sead::Vector3f*, const al::CameraPoser*);
void calcSubTargetTrans(sead::Vector3f*, const al::CameraPoser*);
bool isChangeSubTarget(const al::CameraPoser*);
void calcSubTargetFront(sead::Vector3f*, const al::CameraPoser*);
void getSubTargetRequestDistance(const al::CameraPoser*);
void getSubTargetTurnSpeedRate1(const al::CameraPoser*);
void getSubTargetTurnSpeedRate2(const al::CameraPoser*);
void getSubTargetTurnRestartStep(const al::CameraPoser*);
bool tryCalcSubTargetTurnBrakeDistanceRate(float*, const al::CameraPoser*);
bool isValidSubTargetTurnV(const al::CameraPoser*);
bool isValidSubTargetResetAfterTurnV(const al::CameraPoser*);
void clampAngleSubTargetTurnRangeV(float*, const al::CameraPoser*);
void initCameraVerticalAbsorber(al::CameraPoser*);
void initCameraVerticalAbsorberNoCameraPosAbsorb(al::CameraPoser*);
void getCameraVerticalAbsorbPosUp(const al::CameraPoser*);
void getCameraVerticalAbsorbPosDown(const al::CameraPoser*);
void liberateVerticalAbsorb(al::CameraPoser*);
void stopUpdateVerticalAbsorb(al::CameraPoser*);
void stopUpdateVerticalAbsorbForSnapShotMode(al::CameraPoser*, const sead::Vector3f&);
void restartUpdateVerticalAbsorb(al::CameraPoser*);
void validateVerticalAbsorbKeepInFrame(al::CameraPoser*);
void invalidateVerticalAbsorbKeepInFrame(al::CameraPoser*);
void setVerticalAbsorbKeepInFrameScreenOffsetUp(al::CameraPoser*, float);
void setVerticalAbsorbKeepInFrameScreenOffsetDown(al::CameraPoser*, float);
void initCameraArrowCollider(al::CameraPoser*);
void initCameraArrowColliderWithoutThroughPassCollision(al::CameraPoser*);
void initCameraMoveLimit(al::CameraPoser*);
void initCameraAngleCtrl(al::CameraPoser*);
void initCameraAngleCtrlWithRelativeH(al::CameraPoser*);
void initCameraDefaultAngleRangeV(al::CameraPoser*, float, float);
void setCameraStartAngleV(al::CameraPoser*, float);
void setCameraAngleV(al::CameraPoser*, float);
void getCameraAngleH(const al::CameraPoser*);
void getCameraAngleV(const al::CameraPoser*);
void initAngleSwing(al::CameraPoser*);
bool isValidAngleSwing(const al::CameraPoser*);
void initCameraOffsetCtrlPreset(al::CameraPoser*);
void getOffset(const al::CameraPoser*);
void initGyroCameraCtrl(al::CameraPoser*);
void resetGyro(al::CameraPoser*);
void calcCameraGyroPose(const al::CameraPoser*, sead::Vector3f*, sead::Vector3f*,
                        sead::Vector3f*);
void getGyroFront(al::CameraPoser*);
void getGyroAngleV(al::CameraPoser*);
void getGyroAngleH(al::CameraPoser*);
void setGyroLimitAngleV(al::CameraPoser*, float, float);
void setGyroSensitivity(al::CameraPoser*, float, float);
void reduceGyroSencitivity(al::CameraPoser*);
void stopUpdateGyro(al::CameraPoser*);
void restartUpdateGyro(al::CameraPoser*);
bool isStopUpdateGyro(const al::CameraPoser*);
bool isTargetCollideGround(const al::CameraPoser*);
bool isTargetInWater(const al::CameraPoser*);
bool isTargetInMoonGravity(const al::CameraPoser*);
bool isTargetClimbPole(const al::CameraPoser*);
bool isTargetGrabCeil(const al::CameraPoser*);
bool isTargetInvalidMoveByInput(const al::CameraPoser*);
bool isTargetEnableEndAfterInterpole(const al::CameraPoser*);
bool isTargetWallCatch(const al::CameraPoser*);
bool isSnapShotMode(const al::CameraPoser*);
void initSnapShotCameraCtrl(al::CameraPoser*);
void initSnapShotCameraCtrlZoomAutoReset(al::CameraPoser*);
void initSnapShotCameraCtrlZoomRollMove(al::CameraPoser*);
void validateSnapShotCameraLookAtOffset(al::CameraPoser*);
void validateSnapShotCameraZoomFovy(al::CameraPoser*);
void validateSnapShotCameraRoll(al::CameraPoser*);
void updateSnapShotCameraCtrl(al::CameraPoser*);
void startResetSnapShotCameraCtrl(al::CameraPoser*, int);
void setSnapShotMaxZoomOutFovyDegree(al::CameraPoser*, float);
void getSnapShotRollDegree(const al::CameraPoser*);
void getSnapShotLookAtOffset(const al::CameraPoser*);
bool isOffVerticalAbsorb(const al::CameraPoser*);
void onVerticalAbsorb(al::CameraPoser*);
void offVerticalAbsorb(al::CameraPoser*);
void invalidateCameraBlur(al::CameraPoser*);
bool isRequestStopVerticalAbsorb(const al::CameraObjectRequestInfo&);
bool isRequestResetPosition(const al::CameraObjectRequestInfo&);
bool isRequestResetAngleV(const al::CameraObjectRequestInfo&);
bool isRequestDownToDefaultAngleBySpeed(const al::CameraObjectRequestInfo&);
bool isRequestUpToTargetAngleBySpeed(const al::CameraObjectRequestInfo&);
void getRequestTargetAngleV(const al::CameraObjectRequestInfo&);
void getRequestAngleSpeed(const al::CameraObjectRequestInfo&);
bool isRequestMoveDownAngleV(const al::CameraObjectRequestInfo&);
bool isRequestSetAngleV(const al::CameraObjectRequestInfo&);
void getRequestAngleV(const al::CameraObjectRequestInfo&);
bool isInvalidCollider(const al::CameraPoser*);
void validateCollider(al::CameraPoser*);
void invalidateCollider(al::CameraPoser*);
void validateCtrlSubjective(al::CameraPoser*);
void invalidateChangeSubjective(al::CameraPoser*);
void invalidateKeepDistanceNextCamera(al::CameraPoser*);
void invalidateKeepDistanceNextCameraIfNoCollide(al::CameraPoser*);
void invalidatePreCameraEndAfterInterpole(al::CameraPoser*);
bool isInvalidPreCameraEndAfterInterpole(const al::CameraPoser*);
bool isSceneCameraFirstCalc(const al::CameraPoser*);
bool isActiveInterpole(const al::CameraPoser*);
bool isInvalidEndEntranceCamera(const al::CameraPoser*);
bool isPause(const al::CameraPoser*);
void checkFirstCameraCollisionArrow(sead::Vector3f*, sead::Vector3f*,
                                    const al::IUseCollision*, const sead::Vector3f&,
                                    const sead::Vector3f&);
void checkFirstCameraCollisionArrow(alCameraPoserFunction::CameraCollisionHitResult*,
                                    const al::IUseCollision*, const sead::Vector3f&,
                                    const sead::Vector3f&);
void checkFirstCameraCollisionArrowOnlyCeiling(sead::Vector3f*, sead::Vector3f*,
                                               const al::IUseCollision*,
                                               const sead::Vector3f&,
                                               const sead::Vector3f&);
void checkCameraCollisionMoveSphere(sead::Vector3f*, const al::IUseCollision*,
                                    const sead::Vector3f&, const sead::Vector3f&,
                                    float);
void calcZoneRotateAngleH(float, const al::CameraPoser*);
void calcZoneRotateAngleH(float, const sead::Matrix34f&);
void calcZoneInvRotateAngleH(float, const sead::Matrix34f&);
void multVecZone(sead::Vector3f*, const sead::Vector3f&, const al::CameraPoser*);
void multVecInvZone(sead::Vector3f*, const sead::Vector3f&, const al::CameraPoser*);
void rotateVecZone(sead::Vector3f*, const sead::Vector3f&, const al::CameraPoser*);
void calcOffsetCameraKeepInFrameV(sead::Vector3f*, sead::LookAtCamera*,
                                  const sead::Vector3f&, const al::CameraPoser*, float,
                                  float);
void makeCameraKeepInFrameV(sead::LookAtCamera*, const sead::Vector3f&,
                            const al::CameraPoser*, float, float);
void initCameraRail(al::CameraPoser*, const al::PlacementInfo&, const char*);
bool tryGetCameraRailArg(float*, const al::PlacementInfo&, const char*, const char*);
// void getCameraRailPointObjId(al::CameraPoser const*, int);
bool tryFindNearestLimitRailKeeper(const al::CameraPoser*, const sead::Vector3f&);
sead::Vector2f calcCameraRotateStick(sead::Vector2f*, const al::CameraPoser*);
float calcCameraRotateStickH(const al::CameraPoser*);
float calcCameraRotateStickV(const al::CameraPoser*);
float calcCameraRotateStickPower(const al::CameraPoser*);
int getStickSensitivityLevel(const al::CameraPoser*);
float getStickSensitivityScale(const al::CameraPoser*);
bool isValidGyro(const al::CameraPoser*);
int getGyroSensitivityLevel(const al::CameraPoser*);
float getGyroSensitivityScale(const al::CameraPoser*);
bool isTriggerCameraResetRotate(const al::CameraPoser*);
bool isHoldCameraZoom(const al::CameraPoser*);
bool isHoldCameraSnapShotZoomIn(const al::CameraPoser*);
bool isHoldCameraSnapShotZoomOut(const al::CameraPoser*);
bool isHoldCameraSnapShotRollLeft(const al::CameraPoser*);
bool isHoldCameraSnapShotRollRight(const al::CameraPoser*);
bool tryCalcCameraSnapShotMoveStick(sead::Vector2f*, const al::CameraPoser*);
bool isPlayerTypeFlyer(const al::CameraPoser*);
bool isPlayerTypeHighSpeedMove(const al::CameraPoser*);
bool isPlayerTypeHighJump(const al::CameraPoser*);
bool isPlayerTypeNotTouchGround(const al::CameraPoser*);
bool isOnRideObj(const al::CameraPoser*);
}  // namespace alCameraPoserFunction
