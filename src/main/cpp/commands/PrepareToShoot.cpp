/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrepareToShoot.h"

PrepareToShoot::PrepareToShoot( DriveSubsystem*   driveSubsystem,
                                ShooterSubsystem* shooterSubsystem )
 :
  m_driveSubsystem{driveSubsystem},
  m_shooterSubsystem{shooterSubsystem}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveSubsystem, shooterSubsystem});
}


// Called when the command is initially scheduled.
void PrepareToShoot::Initialize() {
  m_shooterSubsystem->SpinupShooter();
}

// Called repeatedly when this Command is scheduled to run
void PrepareToShoot::Execute() {
  m_driveSubsystem->RotateToTarget();
}

// Called once the command ends or is interrupted.
void PrepareToShoot::End(bool interrupted) {
  m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
  m_shooterSubsystem->SpindownShooter();
}

// Returns true when the command should end.
bool PrepareToShoot::IsFinished() { return false; }
