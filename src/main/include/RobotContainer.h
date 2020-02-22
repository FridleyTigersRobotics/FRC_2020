/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/XboxController.h>

#include <Constants.h>

#include <subsystems/DriveSubsystem.h>
#include <subsystems/ShooterSubsystem.h>
#include <subsystems/IntakeSubsystem.h>
#include <subsystems/ControlPanelSubsystem.h>
#include <subsystems/IndexerSubsystem.h>



#include <commands/DefaultDrive.h>
#include <commands/PrepareToShoot.h>
#include <commands/ControlPanelLower.h>
#include <commands/ControlPanelRaise.h>
#include <commands/IntakePowerCells.h>
#include <commands/RaiseIntake.h>
#include <commands/ChangeShooterAngle.h>
#include <commands/StopShooter.h>


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

 private:
  // The robot's subsystems and commands are defined here...
  DriveSubsystem   m_driveSubsystem;
  ShooterSubsystem m_shooterSubsystem;
  IntakeSubsystem  m_intakeSubsystem;
  IndexerSubsystem  m_indexerSubsystem;
  ControlPanelSubsystem m_controlPanelSubsystem; 

  frc::XboxController m_driverController{ DriverStationConstants::kDriverControllerPort };
  // frc::XboxController m_shooterController{ 1 };

  void ConfigureButtonBindings();


  // Commands
  DefaultDrive      m_defaultDriveCommand;
  PrepareToShoot    m_prepareToShootCommand;
  IntakePowerCells  m_intakePowerCellsCommand;
  ControlPanelRaise m_controlPanelRaiseCommand;
  ControlPanelLower m_controlPanelLowerCommand;
  RaiseIntake       m_raiseIntakeCommand;
  ChangeShooterAngle m_changeShooterAngleComand;
  StopShooter        m_stopShooterCommand;
};
