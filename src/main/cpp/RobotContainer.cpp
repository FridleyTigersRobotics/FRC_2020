/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/XboxController.h>
#include <frc2/command/button/JoystickButton.h>

#include <RobotContainer.h>

#include <frc/GenericHID.h>

#include "frc2/command/button/Button.h"


RobotContainer::RobotContainer() :
  m_driveSubsystem{
    [this] { return m_gyro.GetAngle(); }
  }, 
  m_defaultDriveCommand{
    &m_driveSubsystem,
    [this] { return -m_driverController.GetY( frc::GenericHID::kLeftHand );  },
    [this] { return -m_driverController.GetX( frc::GenericHID::kRightHand ); }
  },
  m_prepareToShootCommand{
    &m_driveSubsystem,
    &m_shooterSubsystem,
    &m_intakeSubsystem,
    false
  },
  m_intakePowerCellsCommand{
    &m_intakeSubsystem,
    &m_indexerSubsystem
  },
  m_defaultIntakeControlCommand{
    &m_intakeSubsystem
  },
  m_raiseIntakeCommand{
    &m_intakeSubsystem
  },
  m_lowerIntakeCommand{
    &m_intakeSubsystem
  },
  m_changeShooterAngleComand{
    &m_shooterSubsystem,
    &m_intakeSubsystem,
    [this] { return m_driverController.GetBumper( frc::GenericHID::kRightHand ); },
    [this] { return m_driverController.GetBumper( frc::GenericHID::kLeftHand ); }
  },
  m_stopShooterCommand{
    &m_shooterSubsystem
  },
  m_indexerInCommand{
     &m_indexerSubsystem
  },
  m_indexerOutCommand{
     &m_indexerSubsystem
  },
  m_indexerStopCommand{
     &m_indexerSubsystem
  },
  m_intakeInCommand{
     &m_intakeSubsystem
  },
  m_intakeOutCommand{
     &m_intakeSubsystem
  },
  m_intakeStopCommand{
     &m_intakeSubsystem
  },
  m_angleShooterUp{
     &m_shooterSubsystem
  },
  m_angleShooterDown{
     &m_shooterSubsystem
  },
  m_shooterHoldAngle{
     &m_shooterSubsystem
  },
  m_autoThreeBallShoot{
    &m_driveSubsystem,
    &m_shooterSubsystem,
    &m_intakeSubsystem,
    &m_indexerSubsystem
  }
{
  // Initialize all of your commands and subsystems here
  
  m_gyro.InitGyro();
  m_gyro.Calibrate();

  // Set up default subsystem commands
  m_driveSubsystem.SetDefaultCommand( m_defaultDriveCommand );
  m_intakeSubsystem.SetDefaultCommand( m_lowerIntakeCommand );
  m_shooterSubsystem.SetDefaultCommand( m_stopShooterCommand );
  m_indexerSubsystem.SetDefaultCommand( m_indexerStopCommand );
  //m_climberSubsystem.SetDefaultCommand( m_climbHold );
  //m_climberHookLiftSubsystem.SetDefaultCommand( m_holdHook );

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc::XboxController* driverController = &m_driverController;

  frc2::Button LeftTrigger = frc2::Button([driverController] {
          return ( driverController->GetTriggerAxis( frc::GenericHID::kLeftHand ) > 0.1 );
        });

  frc2::Button RightTrigger = frc2::Button([driverController] {
          return ( driverController->GetTriggerAxis( frc::GenericHID::kRightHand ) > 0.8 );
        }); 

  LeftTrigger.WhenHeld( m_indexerInCommand );
  RightTrigger.WhenHeld( m_indexerOutCommand );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kA )
      .ToggleWhenPressed( m_raiseIntakeCommand );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kY )
      .WhileHeld( m_intakePowerCellsCommand );


  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperLeft )
      .WhileHeld( m_angleShooterDown );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kBumperRight )
      .WhileHeld( m_angleShooterUp );

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kX ).WhileHeld( m_prepareToShootCommand );

  /*  Button board mapping
          5
    2     4        10    12
    1     3        11 
  */

  frc2::JoystickButton( &m_buttonBoard, (int)10 ).WhileHeld( m_intakeInCommand );
  frc2::JoystickButton( &m_buttonBoard, (int)12 ).WhileHeld( m_intakeOutCommand );


  frc2::JoystickButton( &m_buttonBoard, (int)11 ).WhileHeld( m_loadShooter );

  //frc2::JoystickButton( &m_buttonBoard, (int)3 ).WhenPressed( m_controlPanelLift );
  //frc2::JoystickButton( &m_buttonBoard, (int)4 ).WhileHeld( m_controlPanelRotate );

  //frc2::JoystickButton( &m_buttonBoard, (int)5 ).WhenPressed( RotateAngle( 90, &m_driveSubsystem ) );

  frc2::JoystickButton( &m_buttonBoard, (int)5 ).WhenPressed(  m_climbUp );
  frc2::JoystickButton( &m_buttonBoard, (int)5 ).WhenReleased( m_climbHold );
  //frc2::JoystickButton( &m_buttonBoard, (int)5 ).WhenPressed(  m_climbDown );
  //frc2::JoystickButton( &m_buttonBoard, (int)5 ).WhenReleased( m_climbHold );




  frc2::JoystickButton( &m_buttonBoard, (int)4 ).WhenPressed( m_liftHook  );
  frc2::JoystickButton( &m_buttonBoard, (int)4 ).WhenReleased( m_holdHook  );
  frc2::JoystickButton( &m_buttonBoard, (int)3 ).WhenPressed( m_lowerHook  );
  frc2::JoystickButton( &m_buttonBoard, (int)3 ).WhenReleased( m_holdHook  );
  //frc2::InstantCommand 


#if 0
  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kA )
      .WhileHeld( m_prepareToShootCommand );


  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kY )
      .WhileHeld( m_intakePowerCellsCommand );


  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kB )
      .WhileHeld( m_controlPanelRaiseCommand );


  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kX )
      .WhileHeld( m_changeShooterAngleComand );


  // Spin up shooter when the 'A' button is pressed.
  frc2::JoystickButton( &m_shooterController, (int)3 )
      .WhenPressed( new SpinUpShooter( &m_shooterSubsystem ) );

  // Spin down shooter when the 'A' button is released.
  frc2::JoystickButton( &m_shooterController, (int)3 )
      .WhenReleased( new SpinDownShooter( &m_shooterSubsystem ) );




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

  frc2::JoystickButton( &m_driverController, (int)frc::XboxController::Button::kB )
      .WhenPressed( new ControlPanelRaise( &m_ControlPanelsubsystem ) );
#endif
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  return &m_autoThreeBallShoot;
}
