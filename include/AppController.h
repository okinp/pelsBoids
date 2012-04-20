#pragma once
#include <list>
#include "Boid.h" 
class AppController
{
 public:
    static AppController*   getInstance();
    std::list<Boid>* getBoidList();
 private:
     AppController( void );
    ~AppController( void );
    static AppController* m_Instance;
    std::list<Boid> m_Boids;
};

