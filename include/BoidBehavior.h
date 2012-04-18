#pragma once
#include "cinder/Vector.h"
#include "Binner.h"
#include "Boid.h"

class BoidBehavior {
public:
    BoidBehavior(void);
    virtual ~BoidBehavior(void);
    virtual ci::Vec3f getSteer( Boid *const subject )=0;
protected:
    Binner* m_Binner;
};

