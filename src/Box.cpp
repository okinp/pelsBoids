#include "Box.h"
#include "cinder/gl/gl.h"

//An axis aligned box
Box::Box(void)
    :m_center(ci::Vec3f::zero()), m_side( 770 )
{
    calculateFaces( );
}

Box::Box( ci::Vec3f c1, ci::Vec3f c2 )
    :m_center( 0.5*(c1+c2) ), m_side( abs(c2.x - c1.x) )
{
    calculateFaces( );
}

Box::Box( ci::Vec3f center, float side )
    :m_center( center ), m_side( side )
{
    calculateFaces( );
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

   //      1----2 
   //    / |   /|
   //   4----3  |
   //   |  5-|--6
   //   | /  | /
   //   8----7

    int  a  = 1920;
    int  b =  1080;

   // m_center = ci::Vec3f( a/2, b/2, 0 );
   // m_side = 540;
    ci::Vec3f c1(-1,-1,-1);
    ci::Vec3f c2( 1,-1,-1);
    ci::Vec3f c3( 1,-1, 1);
    ci::Vec3f c4(-1,-1, 1);
    ci::Vec3f c5(-1, 1,-1);
    ci::Vec3f c6( 1, 1,-1);
    ci::Vec3f c7( 1, 1, 1);
    ci::Vec3f c8(-1, 1, 1);

    m_TopFace.UpperLeft  = m_center + 0.5*m_side*c1; 
    m_TopFace.UpperRight = m_center + 0.5*m_side*c2;
    m_TopFace.LowerLeft  = m_center + 0.5*m_side*c4;
    m_TopFace.LowerRight = m_center + 0.5*m_side*c3;
    m_TopFace.Normal     = ci::Vec3f( 0, 1, 0);
   //
   m_BottomFace.UpperLeft  = m_center + 0.5*m_side*c8; 
   m_BottomFace.UpperRight = m_center + 0.5*m_side*c7;
   m_BottomFace.LowerLeft  = m_center + 0.5*m_side*c5;
   m_BottomFace.LowerRight = m_center + 0.5*m_side*c6;
   m_BottomFace.Normal     = ci::Vec3f( 0, -1, 0);
   //
   m_FrontFace.UpperLeft   = m_center + 0.5*m_side*c4; 
   m_FrontFace.UpperRight  = m_center + 0.5*m_side*c3;
   m_FrontFace.LowerLeft   = m_center + 0.5*m_side*c8;
   m_FrontFace.LowerRight  = m_center + 0.5*m_side*c7;
   m_FrontFace.Normal      = ci::Vec3f( 0, 0,-1);
   //
   m_BackFace.UpperLeft   = m_center + 0.5*m_side*c2; 
   m_BackFace.UpperRight  = m_center + 0.5*m_side*c1;
   m_BackFace.LowerLeft   = m_center + 0.5*m_side*c6;
   m_BackFace.LowerRight  = m_center + 0.5*m_side*c5;
   m_BackFace.Normal      = ci::Vec3f( 0, 0, 1);
   //
   m_LeftFace.UpperLeft   = m_center + 0.5*m_side*c1; 
   m_LeftFace.UpperRight  = m_center + 0.5*m_side*c4;
   m_LeftFace.LowerLeft   = m_center + 0.5*m_side*c5;
   m_LeftFace.LowerRight  = m_center + 0.5*m_side*c8;
   m_LeftFace.Normal      = ci::Vec3f( 1, 0, 0);
   //
   m_RightFace.UpperLeft  = m_center + 0.5*m_side*c3; 
   m_RightFace.UpperRight = m_center + 0.5*m_side*c2;
   m_RightFace.LowerLeft  = m_center + 0.5*m_side*c7;
   m_RightFace.LowerRight = m_center + 0.5*m_side*c6; 
   m_RightFace.Normal     = ci::Vec3f( -1, 0, 0);
}

void Box::draw()
{
    //It draws 4 of the lines twice, but doesn't matter.
    glColor3f( 1.0f, 1.0f, 1.0f );
    drawFace( m_RightFace );
    drawFace( m_LeftFace );
    drawFace( m_TopFace );
    drawFace( m_BottomFace );
    drawFace( m_FrontFace );
    drawFace( m_BackFace );
}
CubeFace Box::getFace( FACE_TYPE face ) const
{
    switch ( face )
    {
    case LEFT_FACE:
        return m_LeftFace;
    	break;
    case RIGHT_FACE:
        return m_RightFace;
        break;
    case TOP_FACE:
        return m_TopFace;
        break;
    case BOTTOM_FACE:
        return m_BottomFace;
        break;
    case FRONT_FACE:
        return m_FrontFace;
        break;
    case BACK_FACE:
        return m_BackFace;
        break;
    }
}
void Box::drawFace( const CubeFace& face )
{
    glBegin(GL_LINES);
    glVertex3f( face.UpperLeft.x,  face.UpperLeft.y,  face.UpperLeft.z );    glVertex3f( face.UpperRight.x, face.UpperRight.y, face.UpperRight.z );
    glVertex3f( face.UpperRight.x, face.UpperRight.y, face.UpperRight.z );   glVertex3f( face.LowerRight.x, face.LowerRight.y, face.LowerRight.z );
    glVertex3f( face.LowerRight.x, face.LowerRight.y, face.LowerRight.z );   glVertex3f( face.LowerLeft.x,  face.LowerLeft.y,  face.LowerLeft.z );
    glVertex3f( face.LowerLeft.x,  face.LowerLeft.y,  face.LowerLeft.z );    glVertex3f( face.UpperLeft.x,  face.UpperLeft.y,  face.UpperLeft.z );
    glEnd();
}

bool Box::lineSegmentIntersectsFace( const LineSegment& segment, FACE_TYPE face, float& depth )
{
    CubeFace& selectedFace = getFace( face );
    float denominator = selectedFace.Normal.dot( segment.End - segment.Start );
    if ( denominator == 0)
    {
        return false;
    }
    float nominator =   selectedFace.Normal.dot( selectedFace.UpperLeft - segment.Start );
    float u  = nominator / denominator;
    ci::Vec3f intersectionPoint = u*( segment.End - segment.Start );
    //Get depth & return force needed to avoid the wall.
    ci::Vec3f diff = segment.Start - segment.End;

    depth = ( u - 1 )*diff.dot(selectedFace.Normal);
    return true;
}