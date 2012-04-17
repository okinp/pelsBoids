//
//  Flock.cpp
//  pelsBoids
//
//  Created by Nikolas Psaroudakis on 4/16/12.
//  Copyright (c) 2012 AddictiveLabs. All rights reserved.
//

#include "Flock.h"
#include <iostream>
#include "cinder/Quaternion.h"
#include "cinder/Rand.h"

Flock::Flock()
:m_NumBoids( 500 )
{
    initialize();
}

Flock::Flock( int numBoids )
:m_NumBoids( numBoids)
{
    initialize();
}
Flock::~Flock()
{
    
}

void Flock::update()
{
    std::list<Boid>::iterator boidIter = m_BoidList.begin();
    
    for ( ; boidIter != m_BoidList.end(); ++boidIter )
    {
        boidIter->flock( m_BoidList );
        boidIter->update();
    }
}

void Flock::draw()
{
    std::list<Boid>::iterator boidIter = m_BoidList.begin();
    
    for ( ; boidIter != m_BoidList.end(); ++boidIter )
    {
        boidIter->draw();
    }
}

void Flock::addBoid( Boid b )
{
    m_BoidList.push_back( b );
}
void Flock::initialize()
{
//    addBoid( Boid( ci::Vec2f(0, 0) ));
//    addBoid( Boid( ci::Vec2f(10, 0) ));
//    addBoid( Boid( ci::Vec2f(30, 0) ));
//    addBoid( Boid( ci::Vec2f(0, 43) ));
    for ( int i =0; i < m_NumBoids; ++i ) {
        addBoid( Boid( ci::Vec2f(1700 , 200) + 50*ci::Rand::randVec2f() ));
        addBoid( Boid( ci::Vec2f(0, 0) ));
    }
}















