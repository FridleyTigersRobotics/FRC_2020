/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>


#include "RobotContainer.h"
#include "commands/DefaultDrive.h"
#include "commands/SpinupShooter.h"
#include "commands/SpindownShooter.h"
<<<<<<< HEAD
#include "commands/ToggleIndexer.h"
#include "commands/ToggleIndexerReverse.h"
#include "commands/AngleShooterUp.h"
#include "commands/AngleShooterDown.h"
#include "commands/StopShooterAngle.h"
#include "commands/StopIndexer.h"

#include "commands/StopIntake.h"
#include "commands/ToggleIntake.h"
=======
#include "commands/ControlPanelRaise.h"

>>>>>>> a2bbbdda160127d0051b5b32211817668b685d67


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

  // NOTE: Using `new` here will leak these commands if they are ever no longer
  // needed. This is usually a non-issue as button-bindings tend to be permanent
  // - however, if you wish to avoid this, the commands should be
  // stack-allocated and declared as members of RobotContainer.


  #if 1
  // Spin up shooter when the 'A' button is pressed.
  frc2::JoystickButton( &m_shooterController, (int)3 )
      .WhenPressed( new SpinUpShooter( &m_shooterSubsystem ) );

  // Spin down shooter when the 'A' button is released.
  frc2::JoystickButton( &m_shooterController, (int)3 )
      .WhenReleased( new SpinDownShooter( &m_shooterSubsystem ) );

<<<<<<< HEAD



  frc2::JoystickButton( &m_shooterController, (int)1 )
      .WhenPressed( new ToggleIndexer( &m_indexerSubsystem ) );

  frc2::JoystickButton( &m_shooterController, (int)1 )
      .WhenReleased( new StopIndexer( &m_indexerSubsystem ) );




  frc2::JoystickButton( &m_shooterController, (int)2 )
      .WhenPressed( new ToggleIndexerReverse( &m_indexerSubsystem ) );

  frc2::JoystickButton( &m_shooterController, (int)2 )
      .WhenReleased( new StopIndexer( &m_indexerSubsystem ) );





  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperRight  )
      .WhenPressed( new AngleShooterUp( &m_shooterSubsystem ) );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperRight )
      .WhenReleased( new StopShooterAngle( &m_shooterSubsystem ) );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperLeft )
      .WhenPressed( new AngleShooterDown( &m_shooterSubsystem ) );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperLeft )
      .WhenReleased( new StopShooterAngle( &m_shooterSubsystem ) );





  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kA )
      .WhenPressed( new ToggleIntake( &m_intakeSubsystem ) );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kA )
      .WhenReleased( new StopIntake( &m_intakeSubsystem ) );



  #endif
=======
  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kB )
      .WhenPressed( new ControlPanelRaise( &m_ControlPanelsubsystem ) );


>>>>>>> a2bbbdda160127d0051b5b32211817668b685d67
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
