/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleIndexerReverse.h"
#include "subsystems/IndexerSubsystem.h"
#include "stdio.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ToggleIndexerReverse::ToggleIndexerReverse( IndexerSubsystem* subsystem ) :
  m_IndexerSubsystem{subsystem}
{
  indexerRotating = false;
}

// Called when the command is initially scheduled.
void ToggleIndexerReverse::Initialize() 
{
    //std::cout << "StartIndexer\n";
    m_IndexerSubsystem->StartIndexerReverse();
}
