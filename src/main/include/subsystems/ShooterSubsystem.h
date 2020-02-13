/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem( );

  void Periodic() override;

  void SpinupShooter();

  void SpindownShooter();

  bool IsShooterReady();
  int GetRotationValue();

  void AngleShooterUp(); 

  void AngleShooterDown();

  void StopShooterAngle() ;

 private:
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterLeft;
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterRight;
   frc::PWMVictorSPX                           m_motorAngle;
   frc::AnalogInput                            m_jdRotationA;
   frc::AnalogInput                            m_jdRotationB;
};
