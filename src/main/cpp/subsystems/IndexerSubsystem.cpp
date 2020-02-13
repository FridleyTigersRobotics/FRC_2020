/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "Constants.h"
#include "subsystems/IndexerSubsystem.h"
#include <ctre/Phoenix.h>

IndexerSubsystem::IndexerSubsystem():
    m_conveyorMotor{IndexerSubsystemConstants::kIndexerMotorCanId},
    m_motorShooterLoader{  ShooterConstants::kLoaderMotorPwmId }
{}

// This method will be called once per scheduler run
void IndexerSubsystem::Periodic() {}

void IndexerSubsystem::StartIndexer() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.5 );
    m_motorShooterLoader.Set( -1.0 );
}

void IndexerSubsystem::StopIndexer() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0 );
    m_motorShooterLoader.Set( 0.0 );
}

void IndexerSubsystem::StartIndexerReverse() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.5 );
    m_motorShooterLoader.Set( 1.0 );
}

