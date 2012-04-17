#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
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
};

void pelsBoidsApp::prepareSettings( Settings *settings)
{
    settings->setFullScreen( true );
}

void pelsBoidsApp::setup()
{
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
}
void pelsBoidsApp::mouseDown( MouseEvent event )
{

}

CINDER_APP_BASIC( pelsBoidsApp, RendererGl )
