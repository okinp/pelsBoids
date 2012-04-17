#pragma once
#include <iostream>
#include <list>
#include "cinder/Vector.h"

class Boid {
public:
    Boid();
    Boid( ci::Vec2f position );
    virtual ~Boid();
    virtual void flock( std::list<Boid>& boidList );
    virtual void update();
    virtual void draw();
    
//private:
    ci::Vec2f m_pos;
    ci::Vec2f m_vel;
    ci::Vec2f m_acc;
    virtual ci::Vec2f getSeparation( std::list<Boid>& boidList );
    virtual ci::Vec2f getCohesion( std::list<Boid>& boidList );
    virtual ci::Vec2f getAlignment( std::list<Boid>& boidList );
    virtual ci::Vec2f seek(ci::Vec2f target );
};
