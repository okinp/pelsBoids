#include "SeparationRule.h"
#include "Includes.h"
#include "Binner.h"
#include <list>

SeparationRule::SeparationRule()
{

}

SeparationRule::~SeparationRule()
{

}

ci::Vec3f SeparationRule::getSteer( Boid* const b )
{
    m_Boid = b;
    ci::Vec3f steer = ci::Vec3f::zero();
    int count = 0;
    std::list<Boid>* boidList;
    boidList = m_Binner->getBoidList();
    std::list<Boid>::iterator boidIter = boidList->begin();
    for ( ; boidIter != boidList->end(); ++boidIter )
    {
        ci::Vec3f diff = m_Boid->m_pos - boidIter->m_pos;
#ifdef USE_FAST_INV_SQRT
        float lengthSquared = diff.lengthSquared();
        if ( ( lengthSquared > 0 ) && ( lengthSquared < DESIRED_SEP_SQ ) )
        {
            diff.normalize();
            diff*invSqrt( lengthSquared );
            steer += diff;
            count++;
        }
    }

    if (count > 0) 
    {
        steer /= (float)count;
    }

    if (steer.lengthSquared() > 0) 
    {
        steer.normalize();
        steer *= MAX_SPEED;
        steer -= m_Boid->m_vel;
        steer.limit(MAX_FORCE);
    }
    return steer;
#else
        float length = diff.length();
        if ( ( length > 0 ) && ( length < DESIRED_SEP ) )
        {
            diff.normalize();
            diff/=length;
            steer += diff;
            count++;
        }
    }

    if (count > 0) 
    {
        steer /= (float)count;
    }

    if (steer.length() > 0) 
    {
        steer.normalize();
        steer *= MAX_SPEED;
        steer -= m_Boid->m_vel;
        steer.limit(MAX_FORCE);
    }
    return steer;
#endif
}