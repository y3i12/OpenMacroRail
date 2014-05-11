#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include <vector>

class ofApp : public ofBaseApp
{

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

public:
    ofxUICanvas*         m_gui; 
	  ofArduino	           m_arduino;
	  bool                 m_setupArduino;
    float                m_shotNumber;
    float                m_stepNumber;
    std::vector< int >   m_stepperPins;
    std::vector< int >   m_cameraPins;
};
