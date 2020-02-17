/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelRaise.h"
#include "subsystems/ControlPanelSubsystem.h"

ControlPanelRaise::ControlPanelRaise(ControlPanelSubsystem* Subsystem):
 m_ControlSubsystem{Subsystem}
{
  AddRequirements( { Subsystem } );
}

// Called when the command is initially scheduled.
void ControlPanelRaise::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelRaise::Execute() 
{
  m_ControlSubsystem->LiftControlPanelArm();

  if ( m_ControlSubsystem->IsTopLimitEngaged() )
  {
    m_ControlSubsystem->StartSpinning();
  }
  else
  {
    m_ControlSubsystem->StopSpinning();
  }
}

// Called once the command ends or is interrupted.
void ControlPanelRaise::End(bool interrupted) 
{
  m_ControlSubsystem->StopLift();
  m_ControlSubsystem->StopSpinning();
}

// Returns true when the command should end.
bool ControlPanelRaise::IsFinished() { return false; }
