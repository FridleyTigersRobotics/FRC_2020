/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakePowerCells.h"

IntakePowerCells::IntakePowerCells( IntakeSubsystem*  intakeSubsystem,
                                    IndexerSubsystem* indexerSubsystem ) :
  m_intakeSubsystem {intakeSubsystem},
  m_indexerSubsystem{indexerSubsystem}
{
  AddRequirements( { intakeSubsystem, indexerSubsystem } );
}

// Called when the command is initially scheduled.
void IntakePowerCells::Initialize() 
{
  m_intakeSubsystem->LowerIntake();
  m_intakeSubsystem->StartIntake();
}

// Called repeatedly when this Command is scheduled to run
void IntakePowerCells::Execute() 
{

}

// Called once the command ends or is interrupted.
void IntakePowerCells::End(bool interrupted) 
{
  m_intakeSubsystem->RaiseIntake();
  m_intakeSubsystem->StopIntake();
}

// Returns true when the command should end.
bool IntakePowerCells::IsFinished() { return false; }
