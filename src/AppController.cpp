#include "AppController.h"
AppController* AppController::m_Instance = NULL;
AppController* AppController::getInstance()
{
    if ( !m_Instance )
    {
        m_Instance = new AppController();
    }
    return m_Instance;
}

std::list<Boid>* AppController::getBoidList()
{
    return &m_Boids;
}

void AppController::setBox( ci::Vec3f center, float size )
{
    delete m_Box;
    m_Box = new Box( center, size );
}

Box* AppController::getBox() const
{
    return m_Box;
}

AppController::AppController(void)
    :m_Box( new Box( ci::Vec3f::zero(), 20 ) )
{
   
}

AppController::~AppController(void)
{
    //TODO Implement destructor
}

