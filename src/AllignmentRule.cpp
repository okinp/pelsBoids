#include "AllignmentRule.h"
#include "Includes.h"
#include "AppController.h"
#include <list>


AllignmentRule::AllignmentRule()
{

}

AllignmentRule::~AllignmentRule()
{

}

ci::Vec3f AllignmentRule::getSteer( Boid* const b )
{
    m_Boid = b;
    ci::Vec3f sum = ci::Vec3f::zero();
    int count = 0;
    std::list<Boid>* boidList;
    boidList = m_AppController->getBoidList();
    std::list<Boid>::iterator boidIter = boidList->begin();
    for ( ; boidIter != boidList->end(); ++boidIter )
    {
        ci::Vec3f diff = m_Boid->m_pos - boidIter->m_pos;
        float lengthSq = diff.lengthSquared();
        if ( ( lengthSq > 0 ) && ( lengthSq < DESIRED_ALI_SQ) )
        {
            sum += boidIter->m_vel;
            count++;
        }
    }
#ifdef USE_FAST_INV_SQRT
    if (count > 0) 
    {
        sum /= (float)count;
        float lengthSq = sum.lengthSquared();
        if ( lengthSq > 0 )
        {
            sum*=invSqrt( lengthSq );
        }
        sum*=MAX_SPEED;
        ci::Vec3f steer = sum - m_Boid->m_vel;
        steer.limit(MAX_FORCE);
        return steer;
    } else {
        return ci::Vec3f::zero();
    }
#else
    if (count > 0) 
    {
        sum /= (float)count;
        float length = sum.length();
        if ( length > 0 )
        {
            sum/=length;
        }
        sum*=MAX_SPEED;
        ci::Vec3f steer = sum - m_Boid->m_vel;
        steer.limit(MAX_FORCE);
        return steer;
    } else {
        return ci::Vec3f::zero();
    }
#endif
}