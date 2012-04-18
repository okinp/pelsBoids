#include "Binner.h"
Binner* Binner::m_Instance = NULL;
Binner* Binner::getInstance()
{
    if ( !m_Instance )
    {
        m_Instance = new Binner();
    }
    return m_Instance;
}

std::list<Boid>* Binner::getBoidList()
{
    return &m_Boids;
}

Binner::Binner(void)
{

}

Binner::~Binner(void)
{

}

