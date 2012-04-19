#include "AbstractRule.h"

class AllignmentRule : public AbstractRule
{
public:
    AllignmentRule();
    virtual ~AllignmentRule();
    virtual ci::Vec3f getSteer( Boid* const b );
protected:

private:
};