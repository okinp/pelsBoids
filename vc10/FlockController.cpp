#include "FlockController.h"


FlockController::FlockController(void)
{

}

FlockController::~FlockController(void)
{

}

void FlockController::update( )
{
    m_Flock.update();
}

void FlockController::draw( )
{
    m_Flock.draw();
}

void FlockController::drawBoundingBox()
{

}