#pragma once
#include <list>
#include "Boid.h" 
#include "Box.h"

class Flock;
class AppController
{
 public:
    static AppController*   getInstance();
    std::list<Boid>* getBoidList();
    void setBox( ci::Vec3f center, float size );
    Box* getBox( ) const;
    void setup();
    void update();
    void draw();
    void drawBox();
 protected:
     AppController( void );
    ~AppController( void );
 private:
    static AppController* m_Instance;
    std::list<Boid> m_Boids;
    Box* m_Box;
    Flock* m_Flock;
};

