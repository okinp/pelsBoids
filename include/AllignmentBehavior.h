#pragma once
#include "BoidBehavior.h"
class AllignmentBehavior :
    public BoidBehavior
{
public:
    AllignmentBehavior(void);
    virtual ~AllignmentBehavior(void);
    virtual ci::Vec3f getSteer( Boid *const subject );
};

