#include "Box.h"
//An axis aligned box
Box::Box(void)
    :m_center(ci::Vec3f::zero()), m_side( 10 )
{
    calculateFaces( m_center, m_side );
}

Box::Box( ci::Vec3f c1, ci::Vec3f c2 )
    :m_center( 0.5*(c1+c2) ), m_side( abs(c2.x - c1.x) )
{
    calculateFaces( m_center, m_side );
}

Box::Box( ci::Vec3f center, float side )
    :m_center( center ), m_side( side )
{
    calculateFaces( m_center, m_side );
}

Box::~Box(void)
{

}

void Box::getCenter()
{

}

void Box::getSize()
{

}

void Box::setSize( float side )
{

}

void Box::setCenter( ci::Vec3f center )
{

}

void Box::calculateFaces()
{
    m_TopFace.UpperLeft = ci::Vec3f()
    m_BottomFace = 
    m_LeftFace =  
    m_FrontFace =  
    m_BackFace =  
}

void Box::draw()
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
void drawFace( const CubeFace& face )
{
    glBegin(GL_LINES);
    glVertex3f( face.UpperLeft.x,  face.UpperLeft.y,  face.UpperLeft.z );    glVertex3f( face.UpperRight.x, face.UpperRight.y, face.UpperRight.z );
    glVertex3f( face.UpperRight.x, face.UpperRight.y, face.UpperRight.z ); glVertex3f(   face.LowerRight.x, face.LowerRight.y, face.LowerRight.z );
    glVertex3f( face.LowerRight.x, face.LowerRight.y, face.LowerRight.z ); glVertex3f(   face.LowerLeft.x,  face.LowerLeft.y,  face.LowerLeft.z );
    glVertex3f( face.LowerLeft.x,  face.LowerLeft.y,  face.LowerLeft.z );    glVertex3f( face.UpperLeft.x,  face.UpperLeft.y,  face.UpperLeft.z );
    glEnd();
}