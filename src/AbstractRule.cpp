#include "AbstractRule.h"
#include "Binner.h"
AbstractRule::AbstractRule()
{
    m_Binner = Binner::getInstance();
}
AbstractRule::~AbstractRule()
{

}