/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <stdio.h>

#include "commands/Climber/ClimbHold.h"

ClimbHold::ClimbHold(ClimberSubsystem* climberSubsystem) :
  m_climberSubsystem{ climberSubsystem }
{
  AddRequirements( { climberSubsystem } );
}

// Called when the command is initially scheduled.
void ClimbHold::Initialize() {
  m_climberSubsystem->ClimbHold();
  std::cout << "ClimbHold\n" << std::flush;
}

// Called repeatedly when this Command is scheduled to run
void ClimbHold::Execute() 
{
  //std::cout << "ClimbHold\n";
  
}

// Called once the command ends or is interrupted.
void ClimbHold::End(bool interrupted) {
  m_climberSubsystem->ClimbHold();
}

// Returns true when the command should end.
bool ClimbHold::IsFinished() { return false; }
