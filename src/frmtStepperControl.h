#if !defined __FIRMATA_STEPPER_CONTROL_H__
#define __FIRMATA_STEPPER_CONTROL_H__

#include <vector>

class ofArduino;

class frmtStepperControl
{
public:
  frmtStepperControl( std::vector< int >& theStepperPins, ofArduino& theArduino );
  ~frmtStepperControl( void );

  void step( int theNumberOfSteps = 1 );
  void lock( bool doUpdate = true );
  void unlock( bool doUpdate = true );
  void release( bool doUpdate = true );

public:
   std::vector< int >&  m_stepperPins;
   ofArduino&           m_arduino;
   int                  m_currentStep;

private:
  void stepLogic( int theDirection = 0 );
};

#endif
