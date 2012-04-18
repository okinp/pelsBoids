#pragma once
#include "BoidBehavior.h"
class SeperationBehavior : public BoidBehavior
{
public:
    SeperationBehavior(void);
    virtual ~SeperationBehavior(void);
    virtual ci::Vec3f getSteer( Boid *const subject );
};

