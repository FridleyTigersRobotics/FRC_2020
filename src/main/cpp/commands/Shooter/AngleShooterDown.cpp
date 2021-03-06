/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/AngleShooterDown.h"

AngleShooterDown::AngleShooterDown( ShooterSubsystem* shooterSubsystem ) :
  m_shooterSubsystem{shooterSubsystem}
{
  AddRequirements( { shooterSubsystem } );
}

// Called when the command is initially scheduled.
void AngleShooterDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AngleShooterDown::Execute() {
  m_shooterSubsystem->AngleShooterDown();
}

// Called once the command ends or is interrupted.
void AngleShooterDown::End(bool interrupted) {
  m_shooterSubsystem->StopShooterAngle();
}

// Returns true when the command should end.
bool AngleShooterDown::IsFinished() { return false; }
