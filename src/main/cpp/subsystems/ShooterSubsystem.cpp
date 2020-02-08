/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem( )  : 
    m_motorShooterLeft  { ShooterConstants::kLeftMotorCanId  },
    m_motorShooterRight { ShooterConstants::kRightMotorCanId },
    m_motorShooterLoader{ ShooterConstants::kLoaderMotorPwmId },
    m_jdRotationA       { ShooterConstants::kJDRotationA },
    m_jdRotationB       { ShooterConstants::kJDRotationB }
    {}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {}


void ShooterSubsystem::SpinupShooter() {

    m_motorShooterLeft.Set(  
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
    );
    m_motorShooterRight.Set( 
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
    );
}


void ShooterSubsystem::SpindownShooter() {
    m_motorShooterLeft.NeutralOutput( );
    m_motorShooterRight.NeutralOutput( );
}


bool ShooterSubsystem::IsShooterReady() {
    float const rpmLeft = \
        m_motorShooterLeft.GetSelectedSensorVelocity( 
            ShooterConstants::kSensorId );

    float const rpmRight = \
        m_motorShooterRight.GetSelectedSensorVelocity( 
            ShooterConstants::kSensorId );
            
    bool ready = true;

    if ( rpmLeft < ShooterConstants::ShooterRpmMin &&
         rpmLeft > ShooterConstants::ShooterRpmMax )
    {
        ready = false;
    }

    if ( rpmRight < ShooterConstants::ShooterRpmMin &&
         rpmRight > ShooterConstants::ShooterRpmMax )
    {
        ready = false;
    }

    return ready;
}

int ShooterSubsystem::GetRotationValue() {
   int rotA = m_jdRotationA.GetValue();
   int rotB = m_jdRotationB.GetValue();
   return rotA+rotB;
}
