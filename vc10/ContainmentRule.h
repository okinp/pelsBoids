#pragma once
#include "AbstractRule.h"
#include "cinder/Vector.h"

class ContainmentRule : public AbstractRule {
public:
    ContainmentRule();
    virtual ~ContainmentRule();
    virtual ci::Vec3f getSteer( Boid* const b );
};