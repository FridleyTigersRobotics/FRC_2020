/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "commands/DefaultDrive.h"


RobotContainer::RobotContainer() : m_autonomousCommand(&m_shooterSubsystem) {
  // Initialize all of your commands and subsystems here

  // Set up default drive command
  m_driveSubsystem.SetDefaultCommand(
    DefaultDrive(
      &m_driveSubsystem,
      [this] { return m_driverController.GetY(frc::GenericHID::kLeftHand);  },
      [this] { return m_driverController.GetX(frc::GenericHID::kRightHand); }
    )
  );

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
