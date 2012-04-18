#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include "Flock.h"
#include "FlockController.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class pelsBoidsApp : public AppBasic {
public:
    void prepareSettings( Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    FlockController  m_FlockController;
private:
    ci::Font m_Font;
};

void pelsBoidsApp::prepareSettings( Settings *settings)
{
    settings->setFullScreen( true );
   
}

void pelsBoidsApp::setup()
{
     m_Font = ci::Font("Arial", 48);
    m_FlockController.setBoundingBox(ci::Vec3f(40, 40, 0), ci::Vec3f(640, 1080, -200 ) );

}



void pelsBoidsApp::update()
{
    m_FlockController.update();
}

void pelsBoidsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
    gl::color ( Color::white() );
    m_FlockController.draw();
    m_FlockController.drawBoundingBox();

    gl::drawString( ci::toString( getAverageFps() ), Vec2f( float(getWindowWidth() - 240), 10.0 ), Color(1,0,0), m_Font);
}
void pelsBoidsApp::mouseDown( MouseEvent event )
{

}

CINDER_APP_BASIC( pelsBoidsApp, RendererGl )
