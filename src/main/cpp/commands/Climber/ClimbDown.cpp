/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Climber/ClimbDown.h"

ClimbDown::ClimbDown(ClimberSubsystem* climberSubsystem) :
  m_climberSubsystem{ climberSubsystem }
{
  AddRequirements( { climberSubsystem } );
}

// Called when the command is initially scheduled.
void ClimbDown::Initialize() {
  m_climberSubsystem->ClimbDown();
  std::cout << "ClimbDown\n" << std::flush;
}

// Called repeatedly when this Command is scheduled to run
void ClimbDown::Execute() 
{
  // std::cout << "ClimbUp\n";
  
}

// Called once the command ends or is interrupted.
void ClimbDown::End(bool interrupted) {
  m_climberSubsystem->ClimbHold();
}

// Returns true when the command should end.
bool ClimbDown::IsFinished() { return false; }
