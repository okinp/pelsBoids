#include "ContainmentRule.h"
#include "AppController.h"
#include "Box.h"

ContainmentRule::ContainmentRule()
{

}

ContainmentRule::~ContainmentRule()
{

}

ci::Vec3f ContainmentRule::getSteer( Boid* const b )
{
    Box* worldBox  = AppController::getInstance()->getBox();
    ci::Vec3f currentFramePos = b->m_pos;
    ci::Vec3f vel  = b->m_vel;
    vel += b->m_acc;
    ci::Vec3f nextFramePos = b->m_pos + vel;
    LineSegment segment;
    segment.Start = currentFramePos;
    segment.End   = nextFramePos;
    ci::Vec3f steer( 0.f, 0.f, 0.f );
    float depth = 0;

    if ( worldBox->lineSegmentIntersectsFace( segment, LEFT_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( LEFT_FACE );
        steer = face.Normal; 
    } 
    else if ( worldBox->lineSegmentIntersectsFace( segment, RIGHT_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( RIGHT_FACE );
        steer = face.Normal;
    } 
    else if ( worldBox->lineSegmentIntersectsFace( segment, TOP_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( TOP_FACE );
        steer = face.Normal;
    } 
    else if ( worldBox->lineSegmentIntersectsFace( segment, BOTTOM_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( BOTTOM_FACE );
        steer = face.Normal;
    } 
    else if ( worldBox->lineSegmentIntersectsFace( segment, FRONT_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( FRONT_FACE );
        steer = face.Normal;
    } 
    else if ( worldBox->lineSegmentIntersectsFace( segment, BACK_FACE, depth ) )
    {
        CubeFace face = worldBox->getFace( BACK_FACE );
        steer = face.Normal;
    }
    depth = 0;
    steer*= depth;
    return steer;
}