#include "CohesionRule.h"
#include "Includes.h"
#include "AppController.h"
#include <list>

CohesionRule::CohesionRule()
{

}

CohesionRule::~CohesionRule()
{

}

ci::Vec3f CohesionRule::getSteer( Boid* const b )
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
#ifdef USE_FAST_INV_SQRT
        float lengthSq = diff.lengthSquared();
        if ( ( lengthSq > 0 ) && ( lengthSq < DESIRED_COH_SQ ) )
#else
        float length = diff.length();
        if ( ( length > 0 ) && ( length < DESIRED_COH ) )
#endif
        {
            sum += boidIter->m_pos;
            count++;
        }
    } 
    if (count > 0) 
    {
        sum /= (float)count;
        return seek(sum);
    } else {
        return ci::Vec3f::zero();
    }
}

ci::Vec3f CohesionRule::seek(ci::Vec3f target  )
{

    ci::Vec3f desired = target - m_Boid->m_pos; 
#ifdef USE_FAST_INV_SQRT
    float lengthSq = desired.lengthSquared();
    if ( lengthSq )
    {
        desired*=invSqrt( lengthSq );
    }
#else
    float length = desired.length();
    if ( length )
    {
        desired/=length;
    }
#endif
    desired*=MAX_SPEED;
    ci::Vec3f steer = desired - m_Boid->m_vel;
    steer.limit(MAX_FORCE); 
    return steer;
}