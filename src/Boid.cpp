#include "Boid.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "SeperationBehavior.h"
#include "AllignmentBehavior.h"
#include "CohesionBehavior.h"


Boid::Boid()
:m_pos( ci::Vec3f::zero() ), m_vel( ci::Vec3f::zero() ), m_acc( ci::Vec3f::zero() )
{

}

Boid::Boid( ci::Vec3f position )
:m_pos( position ), m_vel( ci::Vec3f::zero() ), m_acc( ci::Vec3f::zero() )
{
    initRules();
}

Boid::~Boid()
{
    
}

void Boid::initRules()
{
   BoidRule ruleSep = make_pair( new SeperationBehavior(), 1.5 );
   BoidRule ruleAli = make_pair( new AllignmentBehavior(), 1.0  );
   BoidRule ruleCoh = make_pair( new CohesionBehavior(), 1.0  );
   m_Rules.push_back( ruleSep );
   m_Rules.push_back( ruleAli );
   m_Rules.push_back( ruleCoh );
}

void Boid::update( )
{
    m_vel += m_acc;
    m_vel.limit( MAX_SPEED );
    m_pos += m_vel;
    m_acc *= 0;
    if (m_pos.x < -2) m_pos.x = ci::app::App::get()->getWindowWidth()+2;
    if (m_pos.y < -2) m_pos.y = ci::app::App::get()->getWindowHeight()+2;
    if (m_pos.x > ci::app::App::get()->getWindowWidth()+2) m_pos.x  = -2;
    if (m_pos.y > ci::app::App::get()->getWindowHeight()+2) m_pos.y = -2;
}

void Boid::draw()
{
    //ci::gl::drawSolidCircle( ci::Vecpos, 2 );
    glPointSize(3);
    glBegin( GL_POINTS );
    glVertex3f( m_pos.x, m_pos.y, m_pos.z );
    glEnd();
}

void Boid::flock( std::list<Boid>& boidList )
{
    //ci::Vec3f sep = getSeparation( boidList );
    //ci::Vec3f ali = getAlignment( boidList ); 
    //ci::Vec3f  coh = getCohesion( boidList );
    
    std::list<BoidRule>::iterator ruleIter = m_Rules.begin();
    for ( ;ruleIter!=m_Rules.end(); ++ruleIter  )
    {
        ci::Vec3f steer(0.f,0.f,0.f);
        //ci::Vec2f steer = ruleIter->first->getSteer(this) );
        steer*=ruleIter->second;
        m_acc += steer;
    }

//     sep*=1.5;
//     ali*=1.0;
//     coh*=1.0;
//     m_acc += sep;
//     m_acc += ali;
//     m_acc += coh;
}

ci::Vec3f Boid::getSeparation ( std::list<Boid>& boidList ) 
{
    ci::Vec3f steer = ci::Vec3f::zero();
    int count = 0;
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

ci::Vec3f Boid::getAlignment ( std::list<Boid>& boidList ) 
{
    ci::Vec3f sum = ci::Vec3f::zero();
    int count = 0;
    std::list<Boid>::iterator boidIter = boidList.begin();
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec3f diff = m_pos - boidIter->m_pos;
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
        ci::Vec3f steer = sum - m_vel;
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
        ci::Vec3f steer = sum - m_vel;
        steer.limit(MAX_FORCE);
        return steer;
    } else {
        return ci::Vec3f::zero();
    }
#endif
}
    
ci::Vec3f Boid::getCohesion ( std::list<Boid>& boidList ) 
{
    ci::Vec3f sum = ci::Vec3f::zero();
    int count = 0;
    std::list<Boid>::iterator boidIter = boidList.begin();
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec3f diff = m_pos - boidIter->m_pos;
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

ci::Vec3f Boid::seek(ci::Vec3f target )
{
    
    ci::Vec3f desired = target - m_pos; 
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
    ci::Vec3f steer = desired - m_vel;
    steer.limit(MAX_FORCE); 
    return steer;
}

float Boid::invSqrt( float x )
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x; // store floating-point bits in integer
    i = 0x5f3759d5 - (i >> 1); // initial guess for Newton's method
    x = *(float*)&i; // convert new bits into float
    x = x*(1.5f - xhalf*x*x); // One round of Newton's method
    return x;
}