/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include <frc/JoyStick.h>

#include <Constants.h>

#include <subsystems/DriveSubsystem.h>
#include <subsystems/ShooterSubsystem.h>
#include <subsystems/IntakeSubsystem.h>
#include <subsystems/ControlPanelSubsystem.h>
#include <subsystems/IndexerSubsystem.h>



#include <commands/DefaultDrive.h>
#include <commands/PrepareToShoot.h>
#include <commands/ControlPanelRaise.h>
#include <commands/IntakePowerCells.h>
#include <commands/DefaultIntakeControl.h>
#include <commands/RaiseIntake.h>
#include <commands/LowerIntake.h>
#include <commands/ChangeShooterAngle.h>
#include <commands/StopShooter.h>

#include <commands/Indexer/IndexerInCommand.h>
#include <commands/Indexer/IndexerOutCommand.h>
#include <commands/Indexer/IndexerStopCommand.h>

#include <commands/Intake/IntakeInCommand.h>
#include <commands/Intake/IntakeOutCommand.h>
#include <commands/Intake/IntakeStopCommand.h>

#include <commands/Shooter/AngleShooterUp.h>
#include <commands/Shooter/AngleShooterDown.h>
#include <commands/Shooter/ShooterHoldAngle.h>

#include "commands/ControlPanelManipulator/ControlPanelHold.h"
#include "commands/ControlPanelManipulator/ControlPanelLift.h"
#include "commands/ControlPanelManipulator/ControlPanelLower.h"
#include "commands/ControlPanelManipulator/ControlPanelRotate.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 //private:
  // The robot's subsystems and commands are defined here...
  DriveSubsystem   m_driveSubsystem;
  ShooterSubsystem m_shooterSubsystem;
  IntakeSubsystem  m_intakeSubsystem;
  IndexerSubsystem  m_indexerSubsystem;
  ControlPanelSubsystem m_controlPanelSubsystem; 

  frc::XboxController m_driverController{ DriverStationConstants::kDriverControllerPort };
  frc::Joystick       m_buttonBoard{ 1 };

  void ConfigureButtonBindings();


  // Commands
  DefaultDrive         m_defaultDriveCommand;
  PrepareToShoot       m_prepareToShootCommand;
  IntakePowerCells     m_intakePowerCellsCommand;
  ControlPanelRaise    m_controlPanelRaiseCommand;
  DefaultIntakeControl m_defaultIntakeControlCommand;
  RaiseIntake          m_raiseIntakeCommand;
  LowerIntake          m_lowerIntakeCommand;
  ChangeShooterAngle   m_changeShooterAngleComand;
  StopShooter          m_stopShooterCommand;

  // Indexer Commands
  IndexerInCommand   m_indexerInCommand;
  IndexerOutCommand  m_indexerOutCommand;
  IndexerStopCommand m_indexerStopCommand;

  // Intake Commands
  IntakeInCommand   m_intakeInCommand;
  IntakeOutCommand  m_intakeOutCommand;
  IntakeStopCommand m_intakeStopCommand;

  // Shooter Commands
  AngleShooterUp    m_angleShooterUp;
  AngleShooterDown  m_angleShooterDown;
  ShooterHoldAngle  m_shooterHoldAngle;

  // Control Panel Manipulator Commands
  ControlPanelHold    m_controlPanelHold;
  ControlPanelLift    m_controlPanelLift;
  ControlPanelLower   m_controlPanelLower;
  ControlPanelRotate  m_controlPanelRotate;
};
