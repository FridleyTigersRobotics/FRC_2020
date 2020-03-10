/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/DriveSubsystem.h>
#include <stdio.h>

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem( std::function<double()> currentAngle )
    : m_left1{kLeftMotor1Port},
      m_left2{kLeftMotor2Port},
      m_right1{kRightMotor1Port},
      m_right2{kRightMotor2Port},
      m_angleController{kRotationP,kRotationI,kRotationD},
      m_currentAngle{currentAngle}
{
  m_drive.SetMaxOutput( kMaxDriveOutput );
  m_angleController.SetSetpoint( 0.0 );
  m_angleController.SetTolerance( 5.0 );
  m_angleController.SetIntegratorRange( -0.1, 0.1 );
}

double DriveSubsystem::GetAngle() 
{
  return m_currentAngle();
}


// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  //std::cout << "ArcadeDrive: " << fwd << " " << rot << "\n";
  m_drive.ArcadeDrive(-fwd, rot);
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}


void DriveSubsystem::ResetRotationPid()
{
  m_angleController.Reset();
}

bool DriveSubsystem::RotateToTarget()
{
  bool const debugOutput = false;

  extern nt::NetworkTableEntry xEntry;
  double const xVal = xEntry.GetDouble( -1.0 );

  bool atTarget = false;

  if ( debugOutput )
  {
    std::cout << "xVal: " << xVal << "\n";
  }
  

  if ( xVal < 0 )
  {
    m_drive.ArcadeDrive( 0.0, 0.0 );
    atTarget = true;
  }
  else
  {
    double const center = 150;
    double const offset = xVal - center;

    if ( debugOutput )
    {
      std::cout << "offset: " << offset << " " << fabs( offset ) << "\n";
    }

    double const speed = m_angleController.Calculate( offset );
    m_drive.ArcadeDrive( 0.0, speed );

    atTarget = m_angleController.AtSetpoint();
  }

  return atTarget;
}



