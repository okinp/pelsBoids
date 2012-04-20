#include "AbstractRule.h"
#include "AppController.h"
AbstractRule::AbstractRule()
{
    m_AppController = AppController::getInstance();
}
AbstractRule::~AbstractRule()
{

}