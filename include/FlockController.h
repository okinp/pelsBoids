#pragma once
#include "cinder/Vector.h"
#include "Flock.h"
struct bbox
{
    ci::Vec3f p1, p2, p3, p4;
    ci::Vec3f p5, p6, p7, p8;
};

class FlockController
{
public:
    FlockController( void );
    ~FlockController( void );
    void setBoundingBox( ci::Vec3f c1, ci::Vec3f c2 );
    void drawBoundingBox( );
    void update( );
    void draw( );
private:
    Flock m_Flock;
    bbox  m_Box;
};

