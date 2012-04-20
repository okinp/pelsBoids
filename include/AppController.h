#pragma once
#include <list>
#include "Boid.h" 
#include "Box.h"
class AppController
{
 public:
    static AppController*   getInstance();
    std::list<Boid>* getBoidList();
    void setBox( ci::Vec3f center, float size );
    Box* getBox( ) const;
 private:
     AppController( void );
    ~AppController( void );
    static AppController* m_Instance;
    std::list<Boid> m_Boids;
    Box* m_Box;
};

