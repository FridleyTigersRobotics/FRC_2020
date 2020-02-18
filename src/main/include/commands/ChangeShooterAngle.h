/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/ShooterSubsystem.h>
#include <subsystems/IntakeSubsystem.h>
#include <subsystems/ControlPanelSubsystem.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ChangeShooterAngle
    : public frc2::CommandHelper<frc2::CommandBase, ChangeShooterAngle> {
 public:
  ChangeShooterAngle(ShooterSubsystem* shooterSubsystem,
  ControlPanelSubsystem* controlPanelSubsystem,
  IntakeSubsystem*  intakeSubsystem,
  std::function<bool()> up,
  std::function<bool()> down );

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  ShooterSubsystem* m_shooterSubsystem;
  ControlPanelSubsystem* m_controlPanelSubsystem;
  IntakeSubsystem*  m_intakeSubsystem;

  std::function<bool()> m_up;
  std::function<bool()> m_down;

};
