#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Flock.h"

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
    Flock m_Flock;
};
void pelsBoidsApp::prepareSettings( Settings *settings)
{
    settings->setFullScreen( true );
}
void pelsBoidsApp::setup()
{

}

void pelsBoidsApp::mouseDown( MouseEvent event )
{
    
}

void pelsBoidsApp::update()
{
    m_Flock.update();
}

void pelsBoidsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
    gl::color ( Color::white() );
    m_Flock.draw();
}


CINDER_APP_BASIC( pelsBoidsApp, RendererGl )
