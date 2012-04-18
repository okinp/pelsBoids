#include "BoidBehavior.h"
#include "Binner.h"

BoidBehavior::BoidBehavior(void)
{
    m_Binner = Binner::getInstance();
}

BoidBehavior::~BoidBehavior(void)
{

}