#pragma once
#include "cinder/Vector.h"
class Binner;
class Boid;
class AbstractRule {
public:
    AbstractRule();
    virtual ~AbstractRule();
    virtual ci::Vec3f getSteer( Boid* const b ) = 0;
protected:
    Binner* m_Binner;
    Boid*   m_Boid;
    float invSqrt( float x )
    {
        //Fast approximation of inverse square root
        float xhalf = 0.5f * x;
        int i = *(int*)&x;
        i = 0x5f3759d5 - (i >> 1);
        x = *(float*)&i;
        x = x*(1.5f - xhalf*x*x);
        return x;
    }
};