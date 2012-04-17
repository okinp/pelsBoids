#include "Boid.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#define MAX_DIST_SQUARED 2500
#define DESIRED_SEP 25
#define DESIRED_COH 35
#define DESIRED_ALI 50
#define MAX_SPEED 7
#define MAX_FORCE 0.4
Boid::Boid()
:m_pos( ci::Vec2f::zero() ), m_vel( ci::Vec2f::zero() ), m_acc( ci::Vec2f::zero() )
{
    
}

Boid::Boid( ci::Vec2f position )
:m_pos( position ), m_vel( ci::Vec2f::zero() ), m_acc( ci::Vec2f::zero() )
{
    
}

Boid::~Boid()
{
    
}

void Boid::update( )
{
    m_vel += m_acc;
    m_vel.limit( MAX_SPEED );
    m_pos += m_vel;
    m_acc *= 0;
    if (m_pos.x < -2) m_pos.x = ci::app::App::get()->getWindowWidth()+2;
    if (m_pos.y < -2) m_pos.y = ci::app::App::get()->getWindowHeight()+2;
    if (m_pos.x > ci::app::App::get()->getWindowWidth()+2) m_pos.x = -2;
    if (m_pos.y > ci::app::App::get()->getWindowHeight()+2) m_pos.y = -2;
}

void Boid::draw()
{
    ci::gl::drawSolidCircle( m_pos, 2 );
}

void Boid::flock( std::list<Boid>& boidList )
{
    ci::Vec2f sep = getSeparation( boidList );
    ci::Vec2f ali = getAlignment( boidList ); 
    ci::Vec2f  coh = getCohesion( boidList );
    //std::cout << sep << std::endl;
    sep*=1.5;
    ali*=1.0;
    coh*=1.0;
    m_acc += sep;
    m_acc += ali;
    m_acc += coh;
    ////std::cout << "al is: " << ali << std::endl;
}

ci::Vec2f Boid::getSeparation ( std::list<Boid>& boidList ) 
{
    ci::Vec2f steer = ci::Vec2f::zero();
    int count = 0;
    std::list<Boid>::iterator boidIter = boidList.begin();
    
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec2f diff = m_pos - boidIter->m_pos;
        float length = diff.length();
        if ( ( length > 0 ) && ( length < DESIRED_SEP ) )
        {
            diff.normalize();
            diff /= length;
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
}

ci::Vec2f Boid::getAlignment ( std::list<Boid>& boidList ) 
{
    ci::Vec2f sum = ci::Vec2f::zero();
    int count = 0;
    std::list<Boid>::iterator boidIter = boidList.begin();
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec2f diff = m_pos - boidIter->m_pos;
        float length = diff.length();
        if ( ( length > 0 ) && ( length < DESIRED_ALI ) )
        {
            sum += boidIter->m_vel;
            count++;
        }
    }
    if (count > 0) 
    {
        sum /= (float)count;
        sum.safeNormalize();
        sum*=MAX_SPEED;
        ci::Vec2f steer = sum - m_vel;
        steer.limit(MAX_FORCE);
        return steer;
    } else {
        return ci::Vec2f::zero();
    }
}
    
ci::Vec2f Boid::getCohesion ( std::list<Boid>& boidList ) 
{
    ci::Vec2f sum = ci::Vec2f::zero();
    int count = 0;
    std::list<Boid>::iterator boidIter = boidList.begin();
    for ( ; boidIter != boidList.end(); ++boidIter )
    {
        ci::Vec2f diff = m_pos - boidIter->m_pos;
        float length = diff.length();
        if ( ( length > 0 ) && ( length < DESIRED_COH ) )
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
        return ci::Vec2f::zero();
    }
}
ci::Vec2f Boid::seek(ci::Vec2f target )
{
    
    ci::Vec2f desired = target - m_pos; 
    desired.safeNormalize();
    desired*=MAX_SPEED;
    ci::Vec2f steer = desired - m_vel;
    steer.limit(MAX_FORCE); 
    return steer;
}
