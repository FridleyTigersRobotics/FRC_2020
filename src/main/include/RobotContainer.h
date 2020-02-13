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
#include "subsystems/IndexerSubsystem.h"

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
  DriveSubsystem    m_driveSubsystem;
  ShooterSubsystem  m_shooterSubsystem;
  IntakeSubsystem   m_intakeSubsystem;
  IndexerSubsystem  m_indexerSubsystem;
  ExampleCommand    m_autonomousCommand;

  frc::XboxController m_driverController{ DriverStationConstants::kDriverControllerPort };
  frc::XboxController m_shooterController{ 1 };

  void ConfigureButtonBindings();
};
