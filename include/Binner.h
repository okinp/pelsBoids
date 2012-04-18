#pragma once
#include <list>
#include "Boid.h" 
class Binner
{
 public:
    static Binner*   getInstance();
    std::list<Boid>* getBoidList();
 private:
     Binner( void );
    ~Binner( void );
    static Binner* m_Instance;
    std::list<Boid> m_Boids;
};

