#include "SeperationBehavior.h"
#ifndef MAX_DIST_SQUARED
#define MAX_DIST_SQUARED 2500
#endif
#ifndef DESIRED_SEP
#define DESIRED_SEP 25
#endif
#ifndef DESIRED_SEP_SQ
#define DESIRED_SEP_SQ 625
#endif
#ifndef DESIRED_COH
#define DESIRED_COH 35
#endif
#ifndef DESIRED_COH_SQ
#define DESIRED_COH_SQ 1225
#endif
#ifndef DESIRED_ALI
#define DESIRED_ALI 50
#endif
#ifndef DESIRED_ALI_SQ
#define DESIRED_ALI_SQ 50
#endif
#ifndef USE_FAST_INV_SQRT
#define USE_FAST_INV_SQRT
#endif
#ifndef MAX_SPEED
#define MAX_SPEED 7
#endif
#ifndef MAX_FORCE
#define MAX_FORCE 0.4
#endif

SeperationBehavior::SeperationBehavior(void)
{
    m_Binner = Binner::getInstance();
}
SeperationBehavior::~SeperationBehavior(void)
{

}

ci::Vec3f SeperationBehavior::getSteer( Boid* subject )
{
    ci::Vec3f steer = ci::Vec3f::zero();
    int count = 0;
    std::list<Boid> boidList;
    &boidList = m_Binner->getBoidList();
    std::list<Boid>::iterator boidIter = boidList.begin();
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec3f diff = m_pos - boidIter->m_pos;
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
        steer -= m_vel;
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
        steer -= m_vel;
        steer.limit(MAX_FORCE);
    }
    return steer;
#endif
}