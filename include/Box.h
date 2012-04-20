#pragma 
#include "cinder/Vector.h"
struct CubeFace
{
    ci::Vec3f UpperLeft;
    ci::Vec3f UpperRight;
    ci::Vec3f LowerLeft;
    ci::Vec3f LowerRight;
    ci::Vec3f Normal;
};
struct LineSegment
{
    ci::Vec3f Start;
    ci::Vec3f End;
};
enum FACE_TYPE { LEFT_FACE, RIGHT_FACE, TOP_FACE, BOTTOM_FACE, FRONT_FACE, BACK_FACE };
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
    void calculateFaces( );
    void drawFace( const CubeFace& face );
    bool lineSegmentIntersecectsFace( const LineSegment& segment, FACE_TYPE face, float& depth );
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

