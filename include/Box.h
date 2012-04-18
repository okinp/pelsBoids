#pragma 
#include "cinder/Vector.h"
class Box
{
public:
    Box(void);
    Box( ci::Vec3f c1, ci::Vec3f c2 );
    ~Box(void);
    void getCenter();
    void getSize();
    void setSize( float side );
    void setCenter( ci::Vec3f center );
    void draw();
};

