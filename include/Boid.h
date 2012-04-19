#pragma once
#ifndef MAX_DIST_SQUARED
#define MAX_DIST_SQUARED 2500
#endif
#ifndef DESIRED_SEP
#define DESIRED_SEP 25
#endif
#ifndef DESIRED_SEP_SQ
#define DESIRED_SEP_SQ 625
#endif
#ifndef DESIRED_COH
#define DESIRED_COH 35
#endif
#ifndef DESIRED_COH_SQ
#define DESIRED_COH_SQ 1225
#endif
#ifndef DESIRED_ALI
#define DESIRED_ALI 50
#endif
#ifndef DESIRED_ALI_SQ
#define DESIRED_ALI_SQ 50
#endif
//#ifndef USE_FAST_INV_SQRT
//#define USE_FAST_INV_SQRT
//#endif
#ifndef MAX_SPEED
#define MAX_SPEED 7
#endif
#ifndef MAX_FORCE
#define MAX_FORCE 0.4
#endif
#include <iostream>
#include <list>
#include <utility>
#include "boost/shared_ptr.hpp"
#include "cinder/Vector.h"
#include "AbstractRule.h"
using namespace std;

typedef boost::shared_ptr<AbstractRule> AbstractRuleRef;
typedef pair< AbstractRuleRef, float> RulePair;

class Boid {
public:
    Boid();
    Boid( ci::Vec3f position );
    virtual ~Boid();
    virtual void flock( std::list<Boid>* boidList );
    virtual void update();
    virtual void draw();   
//protected:
    ci::Vec3f m_pos;
    ci::Vec3f m_vel;
    ci::Vec3f m_acc;
    virtual void initRules();
    std::list<RulePair> m_Rules;
};
