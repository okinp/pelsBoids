#pragma once
#include "Boid.h"
//#include "BoidBehavior.h"
class CohesionBehavior //:
    //public BoidBehavior
{
public:
    CohesionBehavior(void);
    virtual ~CohesionBehavior(void);
    virtual ci::Vec3f getSteer( Boid* subject );
};

