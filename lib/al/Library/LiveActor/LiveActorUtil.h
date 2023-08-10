#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>
#include "al/Library/LiveActor/LiveActor.h"
#include "al/Library/Nerve/Nerve.h"

namespace al {

template <typename T>
al::LiveActor* createActorFunction(const char* actorName);

const sead::Vector3f& getCameraUp(const al::LiveActor*, int);

const sead::Vector3f& getVelocity(const al::LiveActor* actor);
sead::Vector3f* getVelocityPtr(al::LiveActor* actor);
sead::Vector3f* getGravityPtr(al::LiveActor* actor);

bool isClipped(const LiveActor*);
void tryInitFixedModelGpuBuffer(const LiveActor*);
bool isDead(const LiveActor*);
bool isAlive(const LiveActor*);
bool isHideModel(const LiveActor*);
void hideModelIfShow(al::LiveActor*);
void showModelIfHide(al::LiveActor*);
void setModelAlphaMask(const LiveActor*, float);
const LiveActor* getSubActor(const LiveActor*, const char*);     // NOTE: unknown return type
void onSyncClippingSubActor(LiveActor*, const LiveActor*);
void onSyncHideSubActor(LiveActor*, const LiveActor*);
void onSyncAlphaMaskSubActor(LiveActor*, const LiveActor*);
void setMaterialProgrammable(al::LiveActor*);
bool isExistModel(const al::LiveActor*);
bool isViewDependentModel(const al::LiveActor*);
void calcViewModel(const al::LiveActor*);
void calcQuat(sead::Quatf*, const al::LiveActor*);
void calcJointFrontDir(sead::Vector3f*, const al::LiveActor*, const char*);

float* findActorParamF32(const al::LiveActor*, const char*);
int* findActorParamS32(const al::LiveActor*, const char*);

void setNerveAtActionEnd(al::LiveActor*, const al::Nerve*);
void initActorWithArchiveName(al::LiveActor* actor, const al::ActorInitInfo& info, const sead::SafeString&,
                              const char* suffix);
void initMapPartsActor(al::LiveActor* actor, const al::ActorInitInfo& info, const char* suffix);

void initJointControllerKeeper(const al::LiveActor*, int);
void initJointGlobalQuatController(const al::LiveActor*, const sead::Quatf*, const char*);

bool isEffectEmitting(const IUseEffectKeeper*, const char*);

void registActorToDemoInfo(al::LiveActor* actor, const al::ActorInitInfo& info);

}  // namespace al

namespace rs {

sead::Vector3f* getPlayerPos(const al::LiveActor*);

}
