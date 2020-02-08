/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem( );

  void Periodic() override;

 private:
   // CAN
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterLeft;
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterRight;
};
