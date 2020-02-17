/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/PWMVictorSPX.h>

class IndexerSubsystem : public frc2::SubsystemBase {
 public:
  IndexerSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();
  void StartIndexer();
  void StopIndexer();
  void StartIndexerReverse();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_conveyorMotor;
  ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterLoader;
  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
 