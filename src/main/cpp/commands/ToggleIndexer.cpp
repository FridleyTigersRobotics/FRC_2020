/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleIndexer.h"
#include "subsystems/IndexerSubsystem.h"
#include "stdio.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ToggleIndexer::ToggleIndexer( IndexerSubsystem* subsystem ) :
  m_IndexerSubsystem{subsystem}
{
  indexerRotating = false;
}

// Called when the command is initially scheduled.
void ToggleIndexer::Initialize() {
  
  m_IndexerSubsystem->StartIndexer();
  #if 0
  if (indexerRotating == true)
  {
    //std::cout << "StopIndexer\n";
    m_IndexerSubsystem->StopIndexer();
    indexerRotating = false;
  }
  else
  {
    //std::cout << "StartIndexer\n";
    m_IndexerSubsystem->StartIndexer();
    indexerRotating = true;
  }
  #endif
}
