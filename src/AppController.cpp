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

AppController::AppController(void)
{

}

AppController::~AppController(void)
{

}

