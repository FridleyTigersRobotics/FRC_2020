/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/DriveSubsystem.h>
#include <stdio.h>

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem()
    : m_left1{kLeftMotor1Port},
      m_left2{kLeftMotor2Port},
      m_right1{kRightMotor1Port},
      m_right2{kRightMotor2Port} 
{
  m_drive.SetMaxOutput(1);
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


void DriveSubsystem::RotateToTarget()
{
  bool const debugOutput = true;

  extern nt::NetworkTableEntry xEntry;
  double const xVal = xEntry.GetDouble( -1.0 );

  if ( debugOutput )
  {
    std::cout << "xVal: " << xVal << "\n";
  }
  

  if ( xVal < 0 )
  {
    m_drive.ArcadeDrive( 0.0, 0.0 );
  }
  else
  {
    double const center = 320;
    double const offset = xVal - center;
    if ( debugOutput )
    {
      std::cout << "offset: " << offset << " " << fabs( offset ) << "\n";
    }

    if ( fabs( offset ) > 20 )
    {
      double const minSpeed = 0.4;
      double const speed = fabs( offset ) / 300;
      double const finalSpeed = ( speed < minSpeed ) ? minSpeed : speed;

      if ( offset > 0 )
      {
        std::cout << "rot: " << -finalSpeed  << "\n";
        m_drive.ArcadeDrive( 0.0, -finalSpeed );
      }
      else
      {
        std::cout << "rot: " << finalSpeed  << "\n";
        m_drive.ArcadeDrive( 0.0, finalSpeed );
      }
      
    }
    else
    {
      m_drive.ArcadeDrive( 0.0, 0.0 );
    } 
  }
}



