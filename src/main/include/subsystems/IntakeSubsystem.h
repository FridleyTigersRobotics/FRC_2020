/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DigitalInput.h>
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
  void HoldIntake();

  bool IsTopLimitEngaged();
  bool IsBotLimitEngaged();

 private:
  frc::PWMVictorSPX  m_motorIntakeRotate;
  frc::PWMVictorSPX  m_motorIntakeExtend;
   
  frc::DigitalInput  m_topLimitSwitch;
  frc::DigitalInput  m_botLimitSwitch;

};
