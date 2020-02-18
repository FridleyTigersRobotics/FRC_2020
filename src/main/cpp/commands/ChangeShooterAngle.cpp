/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChangeShooterAngle.h"


ChangeShooterAngle::ChangeShooterAngle( 
  ShooterSubsystem* shooterSubsystem,
  ControlPanelSubsystem* controlPanelSubsystem,
  IntakeSubsystem*  intakeSubsystem,
  std::function<bool()> up,
  std::function<bool()> down 
 ) :
  m_shooterSubsystem{shooterSubsystem},
  m_controlPanelSubsystem{controlPanelSubsystem},
  m_intakeSubsystem{intakeSubsystem},
  m_up{up},
  m_down{down}
{
  AddRequirements( { shooterSubsystem } );
  AddRequirements( { controlPanelSubsystem } );
  AddRequirements( { intakeSubsystem } );
}

int angleCount = 0;

// Called when the command is initially scheduled.
void ChangeShooterAngle::Initialize() {angleCount = 0;}



// Called repeatedly when this Command is scheduled to run
void ChangeShooterAngle::Execute() 
{
  m_controlPanelSubsystem->LiftControlPanelArm();
  m_intakeSubsystem->LowerIntake();


  if ( m_up() )
  {
    m_shooterSubsystem->AngleShooterUp();
  }
  else if ( m_down() )
  {
    m_shooterSubsystem->AngleShooterDown();
  }
  else
  {
    m_shooterSubsystem->StopShooterAngle();
  }
  angleCount++;

  if ( angleCount > 20 )
  {
    std::cout << "angle " << m_shooterSubsystem->GetRotationDegreeA() << " " << m_shooterSubsystem->GetRotationDegreeB() << "\n";
    angleCount = 0;
  }
}

// Called once the command ends or is interrupted.
void ChangeShooterAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool ChangeShooterAngle::IsFinished() { return false; }
