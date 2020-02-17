/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"
#include "stdio.h"

ShooterSubsystem::ShooterSubsystem( )  : 
    m_motorShooterLeft  { ShooterConstants::kLeftMotorCanId  },
    m_motorShooterRight { ShooterConstants::kRightMotorCanId },
    m_motorAngle { ShooterConstants::kAnglePwmId },
    m_ajdA       { ShooterConstants::kjda },
    m_ajdB       { ShooterConstants::kjdb },
    m_jdA        { m_ajdA },
    m_jdB        { m_ajdB }
    {}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {}


void ShooterSubsystem::SpinupShooter() {

    m_motorShooterLeft.Set(  
        //ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //-ShooterConstants::ShooterRpmTarget
        -0.3
    );
    m_motorShooterRight.Set( 
        //ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //ShooterConstants::ShooterRpmTarget
        0.3
    );
}


void ShooterSubsystem::SpindownShooter() {
    m_motorShooterLeft.NeutralOutput( );
    m_motorShooterRight.NeutralOutput( );
}


void ShooterSubsystem::AngleShooterUp() 
{
    //std::cout << "AngleShooterUp\n";
    m_motorAngle.Set( 1.0 );
}

void ShooterSubsystem::AngleShooterDown() 
{
    //std::cout << "AngleShooterDown\n";
    m_motorAngle.Set( -1.0 );
}

void ShooterSubsystem::StopShooterAngle() 
{   
    //std::cout << "StopShooterAngle\n";
    m_motorAngle.Set( 0.0 );
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

double ShooterSubsystem::GetRotationDegreeA() {
   return m_jdA.GetDistance();
}

double ShooterSubsystem::GetRotationDegreeB() {
   return m_jdB.GetDistance();
}

void ShooterSubsystem::ResetEncoder() {
    m_jdA.Reset();  //Reset the Encoder distance to Zero
    m_jdB.Reset();
    m_jdA.SetDistancePerRotation(ShooterConstants::kDistPerRotation);
    m_jdB.SetDistancePerRotation(ShooterConstants::kDistPerRotation);
}



double ShooterSubsystem::CalculateTargetAngleFromCameraValue( double cameraValue ) {
    double const cameraValueMax = 480;  
    return 45.0 * ( cameraValueMax - cameraValue ) / cameraValueMax;
}


void ShooterSubsystem::TiltToTarget() {
   extern nt::NetworkTableEntry yEntry;
   double const yVal = yEntry.GetDouble( -1.0 );
   double const angle = CalculateTargetAngleFromCameraValue( yVal );
   //std::cout << "yVal: " << yVal << " " << angle << "\n"; 
}



