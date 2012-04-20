#include "AppController.h"
#include "Flock.h"
AppController* AppController::m_Instance = 0;
AppController* AppController::getInstance()
{
    if ( m_Instance == 0 )
    {
        m_Instance = new AppController;
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
void AppController::setup()
{
    if ( !m_Flock  )
    {
        m_Flock = new Flock();
    }
}

void AppController::update()
{
    setup();
    m_Flock->update();
}
void AppController::draw()
{
    m_Flock->draw();
}
void AppController::drawBox()
{
    m_Box->draw();
}
AppController::AppController(void)
    :m_Box( new Box( ci::Vec3f(1920/2.,1080./2, 0.), 400 ) ),
     m_Flock( NULL )
{
     
}

AppController::~AppController(void)
{
    //TODO Implement destructor
}

