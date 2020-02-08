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
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ControlPanelRaise::Initialize() {
  m_ControlSubsystem->LiftControlPanelArm();
}

// Called repeatedly when this Command is scheduled to run
void ControlPanelRaise::Execute() {}

// Called once the command ends or is interrupted.
void ControlPanelRaise::End(bool interrupted) {}

// Returns true when the command should end.
bool ControlPanelRaise::IsFinished() { return true; }
