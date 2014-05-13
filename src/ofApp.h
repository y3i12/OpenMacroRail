#if !defined __OF_APP_H__
#define __OF_APP_H__

#include <vector>

#include "ofMain.h"
#include "ofxUI.h"

#include "frmtStepperControl.h"

class ofApp : public ofBaseApp
{
  public:
    enum Constants
    {
      kFocusIndex = 0,
      kShootIndex = 1,
      kShootClickTime = 50,
    };

	public:
		void setup( );
		void update( );
		void draw( );

		void keyPressed( int key );
		void keyReleased (int key );
		void mouseMoved( int x, int y );
		void mouseDragged( int x, int y, int button );
		void mousePressed( int x, int y, int button );
		void mouseReleased( int x, int y, int button );
		void windowResized( int w, int h );
		void dragEvent ( ofDragInfo dragInfo );
		void gotMessage( ofMessage msg );
		
    void exit( ); 
    void guiEvent( ofxUIEventArgs &e );
    
    void setupArduino( const int &version );
    void digitalPinChanged( const int &pinNum );
    void analogPinChanged( const int &pinNum );
    void updateArduino( );

    void focusAndShoot();
    void stabilize();
    void expose();
    void glideToNextPosition();
    void returnToOriginalPos();

    void doTheShootingSequence();

public:
    ///////////////
    // control vars
    int                   m_stepsMoved;
    
    ///////////////
    // arduino vars
    ofArduino	            m_arduino;
	  bool                  m_setupArduino;

    std::vector< int >    m_stepperPins;
    std::vector< int >    m_cameraPins;
    frmtStepperControl*   m_stepperControl;

    //////////
    // UI vars

    // stepping
    float                 m_motorInterval;
    float                 m_shotNumber;
    float                 m_stepNumber;
    bool                  m_reverseSlicing;

    // moving
    bool                  m_movingForward;
    bool                  m_movingBackward;

    // shooting
    float                 m_stabilizationTime;
    float                 m_exposureTime;
    float                 m_focusTime;

    // misc
    ofxUICanvas*          m_gui; 
    ofxUILabel*           m_status;
    ofxUIButton*          m_exitButton;
    ofxUIButton*          m_doIt;
    bool                  m_doItTriggered;
};

#endif
