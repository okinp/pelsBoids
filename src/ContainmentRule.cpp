#include "ContainmentRule.h"
#include "Box.h"

ContainmentRule::ContainmentRule()
{

}
ContainmentRule::~ContainmentRule()
{

}

ci::Vec3f ContainmentRule::getSteer( Boid* const b )
{
    return ci::Vec3f::zero();
}