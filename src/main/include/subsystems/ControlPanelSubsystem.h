/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>
#include <frc/PWMVictorSPX.h>
#include <ctre/Phoenix.h>

class ControlPanelSubsystem : public frc2::SubsystemBase {
 public:
  ControlPanelSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void LiftControlPanelArm();
  void LowerControlPanelArm();
  void StopLift();
  bool IsTopLimitEngaged();
  bool IsBotLimitEngaged();


 private:
  frc::PWMVictorSPX m_liftMotor;
  ctre::phoenix::motorcontrol::can::TalonSRX m_spinMotor;
  frc::DigitalInput m_topLimitSwitch;
  frc::DigitalInput m_botLimitSwitch;

};
