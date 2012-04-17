//
//  Flock.h
//  pelsBoids
//
//  Created by Nikolas Psaroudakis on 4/16/12.
//  Copyright (c) 2012 AddictiveLabs. All rights reserved.
//

#ifndef pelsBoids_Flock_h
#define pelsBoids_Flock_h
#include <list>
#include "cinder/Vector.h"
#include "Boid.h"

class Flock {
public:  
    Flock();
    Flock( int numBoids );
    virtual ~Flock();
    virtual void update();
    virtual void draw();
    void addBoid( Boid b );
private:
    virtual void initialize();
    std::list<Boid> m_BoidList;
    int m_NumBoids;
};
#endif
