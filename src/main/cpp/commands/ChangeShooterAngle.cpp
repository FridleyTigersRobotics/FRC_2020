/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChangeShooterAngle.h"

ChangeShooterAngle::ChangeShooterAngle( ShooterSubsystem* shooterSubsystem ) :
  m_shooterSubsystem{shooterSubsystem}
{
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ChangeShooterAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ChangeShooterAngle::Execute() {}

// Called once the command ends or is interrupted.
void ChangeShooterAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool ChangeShooterAngle::IsFinished() { return false; }
