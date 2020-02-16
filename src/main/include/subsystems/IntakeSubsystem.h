/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AnalogInput.h>
#include <frc/PWMVictorSPX.h>


class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  void StartIntake();
  void StopIntake();
  
  void LowerIntake();
  void RaiseIntake();

 private:

  bool IsTopLimitEngaged();
  bool IsBotLimitEngaged();

  bool m_engageIntake;

  frc::PWMVictorSPX  m_motorIntakeRotate;
  frc::PWMVictorSPX  m_motorIntakeExtend;
   
  frc::AnalogInput   m_topLimitSwitch;
  frc::AnalogInput   m_botLimitSwitch;

};
