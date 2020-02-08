/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem( )  : 
    m_motorShooterLeft { ShooterConstants::kLeftMotorCanId  },
    m_motorShooterRight{ ShooterConstants::kRightMotorCanId } 
    {}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {}
