#pragma once
#include <iostream>
#include <list>
#include <utility>
#include "boost/shared_ptr.hpp"
#include "cinder/Vector.h"
#include "Includes.h"
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
