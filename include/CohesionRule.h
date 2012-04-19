#include "AbstractRule.h"

class CohesionRule : public AbstractRule
{
public:
    CohesionRule();
    virtual ~CohesionRule();
    virtual ci::Vec3f getSteer( Boid* const b );
protected:

private:
    ci::Vec3f seek( ci::Vec3f target  );
};