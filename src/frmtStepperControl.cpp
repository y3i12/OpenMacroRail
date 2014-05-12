#include "frmtStepperControl.h"
#include "ofArduino.h"
#include "ofLog.h"

frmtStepperControl::frmtStepperControl( std::vector< int >& theStepperPins, ofArduino& theArduino ) :
  m_stepperPins( theStepperPins ),
  m_arduino( theArduino ),
  m_currentStep( -1 )
{
  if ( m_stepperPins.size() != 4 )
  {
    ofLogFatalError() << "Unsuported stepper - it needs to have 4 pins!"; 
    throw std::exception( "Unsuported stepper - it needs to have 4 pins!" );
  }
}

frmtStepperControl::~frmtStepperControl( void )
{
}

void frmtStepperControl::step( int theNumberOfSteps )
{
  if ( !m_arduino.isArduinoReady() )
  {
    ofLogWarning() << "Arduino is not ready, stepper will skip " << theNumberOfSteps << " step(s)";
    return;
  }

  int direction = 1;

  if ( theNumberOfSteps < 0 )
  {
    direction = -1;
    theNumberOfSteps = abs( theNumberOfSteps );
  }

  for ( int i = 0; i < theNumberOfSteps; ++i )
  {
    stepLogic( ARD_LOW );

    m_currentStep = ( m_currentStep + direction + 8 ) % 8;
    
    stepLogic( ARD_HIGH );
  }
}

void frmtStepperControl::lock( bool doUpdate )
{
  for ( auto pin : m_stepperPins )
  {
    m_arduino.sendDigital( m_stepperPins[ pin ], ARD_HIGH );
  }

  if ( doUpdate )
  {
    m_arduino.update();
  }
}

void frmtStepperControl::unlock( bool doUpdate )
{
  release( false );
  stepLogic( ARD_HIGH );
}

void frmtStepperControl::release( bool doUpdate )
{
  for ( auto pin : m_stepperPins )
  {
    m_arduino.sendDigital( m_stepperPins[ pin ], ARD_LOW );
  }
}

void frmtStepperControl::stepLogic( int value )
{
  if ( m_currentStep < 0 || m_currentStep >= 8 )
  {
    return;
  }

  // the main step
  m_arduino.sendDigital( m_stepperPins[ m_currentStep / 2 ], value );
    
  // the half step
  if ( m_currentStep % 2 )
  {
    m_arduino.sendDigital( m_stepperPins[ ( ( m_currentStep / 2 ) + 1 ) % 4 ], value );
  }
}
