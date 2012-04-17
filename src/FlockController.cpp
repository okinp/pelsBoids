#include "FlockController.h"
#include "cinder/gl/gl.h"

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
void FlockController::setBoundingBox( ci::Vec3f c1, ci::Vec3f c2 )
{
    ci::Vec3f diff = c2 - c1;
    float cubeDim = sqrt( 3. )*diff.length()/3.;
    m_Box.p1 = c1; 
    m_Box.p2 = m_Box.p1 + cubeDim*ci::Vec3f( 1, 0, 0 );
    m_Box.p3 = m_Box.p1 + cubeDim*ci::Vec3f( 1, 0, -1 );
    m_Box.p4 = m_Box.p1 + cubeDim*ci::Vec3f( 0, 0, -1 );

    m_Box.p5 = m_Box.p1 + cubeDim*ci::Vec3f(  0, 1, 0 );
    m_Box.p6 = m_Box.p1 + cubeDim*ci::Vec3f(  1, 1, 0 );

    m_Box.p7 = m_Box.p1 + cubeDim*ci::Vec3f(  1, 1, -1 );
    m_Box.p8 = m_Box.p1 + cubeDim*ci::Vec3f( 0, 1, -1 );
}

void FlockController::drawBoundingBox()
{
    glColor3f( 1.0f, 1.0f, 1.0f );
    glBegin(GL_LINES);
     glVertex3f( m_Box.p1.x, m_Box.p1.y, m_Box.p1.z ); glVertex3f( m_Box.p2.x, m_Box.p2.y, m_Box.p2.z );
     glVertex3f( m_Box.p2.x, m_Box.p2.y, m_Box.p2.z ); glVertex3f( m_Box.p3.x, m_Box.p3.y, m_Box.p3.z );
     glVertex3f( m_Box.p3.x, m_Box.p3.y, m_Box.p3.z ); glVertex3f( m_Box.p4.x, m_Box.p4.y, m_Box.p4.z );
     glVertex3f( m_Box.p4.x, m_Box.p4.y, m_Box.p4.z ); glVertex3f( m_Box.p1.x, m_Box.p1.y, m_Box.p1.z );
//     //
     glVertex3f( m_Box.p5.x, m_Box.p5.y, m_Box.p5.z ); glVertex3f( m_Box.p6.x, m_Box.p6.y, m_Box.p6.z );
     glVertex3f( m_Box.p6.x, m_Box.p6.y, m_Box.p6.z ); glVertex3f( m_Box.p7.x, m_Box.p7.y, m_Box.p7.z );
     glVertex3f( m_Box.p7.x, m_Box.p7.y, m_Box.p7.z ); glVertex3f( m_Box.p8.x, m_Box.p8.y, m_Box.p8.z );
     glVertex3f( m_Box.p8.x, m_Box.p8.y, m_Box.p8.z ); glVertex3f( m_Box.p5.x, m_Box.p5.y, m_Box.p5.z );
//     //
    glVertex3f( m_Box.p8.x, m_Box.p8.y, m_Box.p8.z ); glVertex3f( m_Box.p4.x, m_Box.p4.y, m_Box.p4.z );
    glVertex3f( m_Box.p7.x, m_Box.p7.y, m_Box.p7.z ); glVertex3f( m_Box.p3.x, m_Box.p3.y, m_Box.p3.z );
    glVertex3f( m_Box.p6.x, m_Box.p6.y, m_Box.p6.z ); glVertex3f( m_Box.p2.x, m_Box.p2.y, m_Box.p2.z );
    glVertex3f( m_Box.p5.x, m_Box.p5.y, m_Box.p5.z ); glVertex3f( m_Box.p1.x, m_Box.p1.y, m_Box.p1.z );

   glEnd();
}