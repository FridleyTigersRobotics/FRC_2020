/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ControlPanelManipulator/ControlPanelRotate.h"

ControlPanelRotate::ControlPanelRotate(ControlPanelSubsystem* Subsystem):
 m_ControlSubsystem{Subsystem}
{
  AddRequirements( { Subsystem } );
}

// Called when the command is initially scheduled.
void ControlPanelRotate::Initialize() {
  m_ControlSubsystem->StopLift();
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelRotate::Execute() {
  m_ControlSubsystem->StartSpinning();
}

// Called once the command ends or is interrupted.
void ControlPanelRotate::End(bool interrupted) {
  m_ControlSubsystem->StopSpinning();
}

// Returns true when the command should end.
bool ControlPanelRotate::IsFinished() { return false; }
