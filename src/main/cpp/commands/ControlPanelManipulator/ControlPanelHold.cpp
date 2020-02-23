/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelManipulator/ControlPanelHold.h"

ControlPanelHold::ControlPanelHold(ControlPanelSubsystem* Subsystem):
 m_ControlSubsystem{Subsystem}
{
  AddRequirements( { Subsystem } );
}

// Called when the command is initially scheduled.
void ControlPanelHold::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ControlPanelHold::Execute() 
{
  m_ControlSubsystem->StopLift();
  m_ControlSubsystem->StopSpinning();
}
// Called once the command ends or is interrupted.
void ControlPanelHold::End(bool interrupted) {}

// Returns true when the command should end.
bool ControlPanelHold::IsFinished() { return false; }
