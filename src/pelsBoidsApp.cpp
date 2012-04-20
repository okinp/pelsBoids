#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"
#include "AppController.h"


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
    AppController*  m_FlockController;
private:
    ci::Font m_Font;
};

void pelsBoidsApp::prepareSettings( Settings *settings)
{
    //settings->setFullScreen( true );
   settings->setWindowSize(1920,1080);
}

void pelsBoidsApp::setup()
{
     m_Font = ci::Font("Arial", 48);
     m_FlockController = AppController::getInstance();
    // m_FlockController->setBox(ci::Vec3f(40, 40, 0), 50);

}

void pelsBoidsApp::update()
{
    m_FlockController->update();
}

void pelsBoidsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
    gl::color ( Color::white() );
    m_FlockController->draw();
    m_FlockController->drawBox();

    gl::drawString( ci::toString( getAverageFps() ), Vec2f( float(getWindowWidth() - 240), 10.0 ), Color(1,0,0), m_Font);
}
void pelsBoidsApp::mouseDown( MouseEvent event )
{

}

CINDER_APP_BASIC( pelsBoidsApp, RendererGl )
