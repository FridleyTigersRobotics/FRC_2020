/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelManipulator/ControlPanelLift.h"

ControlPanelLift::ControlPanelLift(ControlPanelSubsystem* Subsystem):
 m_ControlSubsystem{Subsystem}
{
  AddRequirements( { Subsystem } );
  lift = false;
}

// Called when the command is initially scheduled.
void ControlPanelLift::Initialize() {
  lift = !lift;
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelLift::Execute() {
  if ( lift == true )
  {
    m_ControlSubsystem->LiftControlPanelArm();
  }
  else
  {
    m_ControlSubsystem->LowerControlPanelArm();
  }
}

// Called once the command ends or is interrupted.
void ControlPanelLift::End(bool interrupted) {
  m_ControlSubsystem->StopLift();
}

// Returns true when the command should end.
bool ControlPanelLift::IsFinished() { 
  if ( ( ( lift == true ) && ( m_ControlSubsystem->IsTopLimitEngaged() ) ) ||
       ( ( lift == false) && ( m_ControlSubsystem->IsBotLimitEngaged() ) ) )
  {
     return true; 
  }
  else
  {
     return false; 
  }
}
