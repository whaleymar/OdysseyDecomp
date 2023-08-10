#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "al/Library/Collision/IUseCollision.h"
#include "al/Library/HostIO/HioNode.h"

namespace al {
struct SphereInterpolator;
struct SphereHitInfo;
struct CollisionPartsFilterBase;
struct TriangleFilterBase;
class CollisionDirector;

class Collider : public HioNode, public IUseCollision {
public:
    Collider(CollisionDirector*, const sead::Matrix34f*, const sead::Vector3f*,
             const sead::Vector3f*, float, float, u32);
    void calcCheckPos(sead::Vector3f*);
    void calcMovePowerByContact(sead::Vector3f*, const sead::Vector3f&);
    void clear();
    void clearContactPlane();
    void clearStoredPlaneNum();
    sead::Vector3f collide(const sead::Vector3f&);
    void findCollidePos(int*, SphereInterpolator*, SphereHitInfo*, u32);
    void getPlane(int);
    void getRecentOnGroundNormal(u32);
    void obtainMomentFixReaction(SphereHitInfo*, sead::Vector3f*, sead::Vector3f*, bool, u32);
    void onInvalidate();
    void preCollide(SphereInterpolator*, sead::Vector3f*, float*, const sead::Vector3f&,
                    SphereHitInfo*, u32);
    void setCollisionPartsFilter(const CollisionPartsFilterBase*);
    void setTriangleFilter(const TriangleFilterBase*);
    void storeContactPlane(SphereHitInfo*);
    void storeCurrentHitInfo(SphereHitInfo*, u32);
    void updateRecentOnGroundInfo();
};

}  // namespace al
