#include "AbstractRule.h"

class SeparationRule : public AbstractRule
{
 public:
     SeparationRule();
     virtual ~SeparationRule();
     virtual ci::Vec3f getSteer( Boid* const b );
 protected:
     
 private:
};