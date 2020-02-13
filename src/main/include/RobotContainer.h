/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Constants.h"
#include <frc2/command/Command.h>
#include <frc/XboxController.h>
#include "commands/ExampleCommand.h"

#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
<<<<<<< HEAD
#include "subsystems/IndexerSubsystem.h"
=======
#include "subsystems/ControlPanelSubsystem.h"
>>>>>>> a2bbbdda160127d0051b5b32211817668b685d67

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
<<<<<<< HEAD
  DriveSubsystem    m_driveSubsystem;
  ShooterSubsystem  m_shooterSubsystem;
  IntakeSubsystem   m_intakeSubsystem;
  IndexerSubsystem  m_indexerSubsystem;
  ExampleCommand    m_autonomousCommand;
=======
  DriveSubsystem   m_driveSubsystem;
  ShooterSubsystem m_shooterSubsystem;
  IntakeSubsystem  m_intakeSubsystem;
  ExampleCommand   m_autonomousCommand;
  ControlPanelSubsystem m_ControlPanelsubsystem; 
>>>>>>> a2bbbdda160127d0051b5b32211817668b685d67

  frc::XboxController m_driverController{ DriverStationConstants::kDriverControllerPort };
  frc::XboxController m_shooterController{ 1 };

  void ConfigureButtonBindings();
};
