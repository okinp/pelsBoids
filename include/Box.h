#pragma 
#include "cinder/Vector.h"
struct CubeFace
{
    ci::Vec3f UpperLeft;
    ci::Vec3f UpperRight;
    ci::Vec3f BottomLeft;
    ci::Vec3f BottomRight;
};

class Box
{
public:
    Box(void);
    Box( ci::Vec3f c1, ci::Vec3f c2 );
    Box( ci::Vec3f center, float side );
    ~Box(void);
    void getCenter();
    void getSize();
    void setSize( float side );
    void setCenter( ci::Vec3f center );
    void calculateFaces( ci::Vec3f center, float side );
    void drawFace( const CubeFace& face );
    void draw();
    CubeFace m_TopFace;
    CubeFace m_BottomFace;
    CubeFace m_LeftFace;
    CubeFace m_RightFace;
    CubeFace m_FrontFace;
    CubeFace m_BackFace;

    float m_side;
    ci::Vec3f m_center;
};

