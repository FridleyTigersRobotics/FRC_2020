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
#include <frc/AnalogEncoder.h>
#include <frc/AnalogInput.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem( );

  void Periodic() override;

  void SpinupShooter();

  void SpindownShooter();

  bool IsShooterReady();

  double GetRotationDegreeA();

  double GetRotationDegreeB();

  void ResetEncoder();

  void AngleShooterUp(); 

  void AngleShooterDown();

  void StopShooterAngle() ;

 private:
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterLeft;
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterRight;
<<<<<<< HEAD
   frc::PWMVictorSPX                           m_motorAngle;
   frc::AnalogInput                            m_jdRotationA;
   frc::AnalogInput                            m_jdRotationB;
=======
   frc::PWMVictorSPX                           m_motorShooterLoader;
   frc::AnalogInput                            m_ajdA;
   frc::AnalogInput                            m_ajdB;
   frc::AnalogEncoder                          m_jdA;
   frc::AnalogEncoder                          m_jdB;
>>>>>>> a2bbbdda160127d0051b5b32211817668b685d67
};
