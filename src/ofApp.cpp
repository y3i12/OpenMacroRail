#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup()
{
  ofSetVerticalSync( true );
  ofSetFrameRate( 60 );
  m_gui = new ofxUICanvas( );

  ofxUISlider* aSlider = 0;
  m_shotNumber = 25.0f;
  aSlider = m_gui->addSlider( "Shot Number", 1.0f, 250.0f, &m_shotNumber );
  aSlider->setLabelPrecision( 0 );

  m_stepNumber = 4.0f;
  aSlider = m_gui->addSlider( "Step/Shot", 1.0f, 50.0f, &m_stepNumber );
  aSlider->setLabelPrecision( 0 );

  m_gui->autoSizeToFitWidgets( ); 
  ofAddListener( m_gui->newGUIEvent, this, &ofApp::guiEvent ); 
  m_gui->loadSettings( "settings.xml" );
  
  // define the pins usd by the software
  m_stepperPins.push_back( 2 );
  m_stepperPins.push_back( 3 );
  m_stepperPins.push_back( 4 );
  m_stepperPins.push_back( 5 );

  m_cameraPins.push_back( 12 );
  m_cameraPins.push_back( 13 );
  
  // create the stepper controller
  m_stepperControl = new frmtStepperControl( m_stepperPins, m_arduino );

  m_setupArduino  = false;  // flag so we setup arduino when its ready, you don't need to touch this :)
  
  // listen for EInitialized notification. this indicates that
  // the arduino is ready to receive commands and it is safe to
  // call setupArduino()
  ofAddListener( m_arduino.EInitialized, this, &ofApp::setupArduino );

  // replace the string below with the serial port for your Arduino board
  // you can get this from the Arduino application or via command line
  // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
  m_arduino.connect( "COM5", 57600 );
}

//--------------------------------------------------------------

void ofApp::update( )
{
	updateArduino( );
}

//--------------------------------------------------------------

void ofApp::draw( )
{

}

//--------------------------------------------------------------

void ofApp::keyPressed( int key )
{

}

//--------------------------------------------------------------

void ofApp::keyReleased( int key )
{

}

//--------------------------------------------------------------

void ofApp::mouseMoved( int x, int y )
{

}

//--------------------------------------------------------------

void ofApp::mouseDragged( int x, int y, int button )
{

}

//--------------------------------------------------------------

void ofApp::mousePressed( int x, int y, int button )
{

}

//--------------------------------------------------------------

void ofApp::mouseReleased( int x, int y, int button )
{

}

//--------------------------------------------------------------

void ofApp::windowResized( int w, int h )
{

}

//--------------------------------------------------------------

void ofApp::gotMessage( ofMessage msg )
{

}

//--------------------------------------------------------------

void ofApp::dragEvent( ofDragInfo dragInfo )
{ 

}

//--------------------------------------------------------------

void ofApp::exit( )
{
    m_gui->saveSettings( "settings.xml" );
    delete m_gui; 
    delete m_stepperControl;
}

//--------------------------------------------------------------

void ofApp::guiEvent( ofxUIEventArgs &e )
{
}

//--------------------------------------------------------------

void ofApp::setupArduino( const int & version ) 
{
  
  // remove listener because we don't need it anymore
  ofRemoveListener(m_arduino.EInitialized, this, &ofApp::setupArduino);
    
  // it is now safe to send commands to the Arduino
  m_setupArduino = true;
    
  // print firmware name and version to the console
  ofLogNotice() << m_arduino.getFirmwareName(); 
  ofLogNotice() << "firmata v" << m_arduino.getMajorFirmwareVersion() << "." << m_arduino.getMinorFirmwareVersion();
        
  // initialize the arduino pins to control the step motor and the camera
  for ( auto pin : m_stepperPins )
  {
    m_arduino.sendDigitalPinMode( pin, ARD_OUTPUT );
  }
        
  for ( auto pin : m_cameraPins )
  {
    m_arduino.sendDigitalPinMode( pin, ARD_OUTPUT );
  }
  
  // Listen for changes on the digital and analog pins
  //ofAddListener( m_arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged );
  //ofAddListener( m_arduino.EAnalogPinChanged,  this, &ofApp::analogPinChanged  );    
}

//--------------------------------------------------------------

void ofApp::updateArduino( )
{

  // update the arduino, get any data or messages.
  // the call to m_arduino.update() is required
  m_arduino.update( );
  
  // do not send anything until the arduino has been set up
  if ( m_setupArduino ) 
  {
    m_stepperControl->step( -1 );
    Sleep( 300 );
  }
}

// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------

void ofApp::digitalPinChanged( const int & pinNum ) 
{
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    //buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(m_arduino.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------

void ofApp::analogPinChanged( const int & pinNum ) 
{
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    // potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(m_arduino.getAnalog(pinNum));
}