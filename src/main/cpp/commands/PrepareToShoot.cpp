/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrepareToShoot.h"

PrepareToShoot::PrepareToShoot( 
  DriveSubsystem*   driveSubsystem,
  ShooterSubsystem* shooterSubsystem,
  IntakeSubsystem*  intakeSubsystem )
 :
  m_driveSubsystem{driveSubsystem},
  m_shooterSubsystem{shooterSubsystem},
  m_intakeSubsystem{intakeSubsystem}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveSubsystem, shooterSubsystem, intakeSubsystem});
}


// Called when the command is initially scheduled.
void PrepareToShoot::Initialize() {
  extern nt::NetworkTableEntry ledStateEntry;
  ledStateEntry.SetDouble( 1 );
  m_shooterSubsystem->SpinupShooter();
}

// Called repeatedly when this Command is scheduled to run
void PrepareToShoot::Execute() {
  if ( m_intakeSubsystem->IsBotLimitEngaged() == false )
  {
    m_shooterSubsystem->StopShooterAngle();
    m_intakeSubsystem->LowerIntake();
    m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
  }
  else
  {
    m_intakeSubsystem->HoldIntake();
    m_driveSubsystem->RotateToTarget();
    m_shooterSubsystem->TiltToTarget();
  }
}

// Called once the command ends or is interrupted.
void PrepareToShoot::End(bool interrupted) {
  extern nt::NetworkTableEntry ledStateEntry;
  ledStateEntry.SetDouble( 0 );

  m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
  m_shooterSubsystem->SpindownShooter();
  //m_shooterSubsystem->StopShooterAngle();
}

// Returns true when the command should end.
bool PrepareToShoot::IsFinished() { return false; }
