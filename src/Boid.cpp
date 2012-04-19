#include "Boid.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "SeparationRule.h"
#include "AllignmentRule.h"
#include "CohesionRule.h"

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
    //TODO:  How does an stl container of base class behave when it contains derived objects?? ( is destructor ok?? )

   //Separation
   boost::shared_ptr<SeparationRule> ruleA( new SeparationRule() );
   RulePair ruleSep = make_pair(ruleA, 1.5f);
   //Allignment
   boost::shared_ptr<AllignmentRule> ruleB( new AllignmentRule() );
   RulePair ruleAli = make_pair(ruleB, 1.0f);
   //Cohesion
   boost::shared_ptr<CohesionRule> ruleC( new CohesionRule() );
   RulePair ruleCoh = make_pair(ruleC, 1.0f);
   //
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

void Boid::flock( std::list<Boid>* boidList )
{
    //ci::Vec3f sep = getSeparation( boidList );
    //ci::Vec3f ali = getAlignment( boidList ); 
    //ci::Vec3f  coh = getCohesion( boidList );
    
    std::list<RulePair>::iterator ruleIter = m_Rules.begin();
    for ( ;ruleIter!=m_Rules.end(); ++ruleIter  )
    {
        //ci::Vec3f steer(0.f,0.f,0.f);
        ci::Vec3f steer = ruleIter->first->getSteer(this);
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



