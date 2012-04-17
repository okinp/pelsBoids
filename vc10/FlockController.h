#pragma once
#include "cinder/Vector.h"
#include "Flock.h"
class FlockController
{
public:
    FlockController( void );
    ~FlockController( void );
    void setBoundingBox( ci::Vec3f c1, ci::Vec3f c2 );
    void drawBoundingBox();
    void update( );
    void draw( );
private:
    Flock m_Flock;
   // ci::Vec3f 
};

