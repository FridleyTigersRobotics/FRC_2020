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
{
    int kTimeoutMs = 30;
    m_motorShooterLeft.ConfigFactoryDefault();
    m_motorShooterLeft.SetInverted(true);
    /* first choose the sensor */
    m_motorShooterLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, ShooterConstants::kSensorId, kTimeoutMs);
    m_motorShooterLeft.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    m_motorShooterLeft.ConfigNominalOutputForward(0, kTimeoutMs);
    m_motorShooterLeft.ConfigNominalOutputReverse(0, kTimeoutMs);
    m_motorShooterLeft.ConfigPeakOutputForward(1, kTimeoutMs);
    m_motorShooterLeft.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    double const F = 0.0420;
    double const P = 0.25;

    m_motorShooterLeft.Config_kF(ShooterConstants::kSensorId, F, kTimeoutMs);
    m_motorShooterLeft.Config_kP(ShooterConstants::kSensorId, P, kTimeoutMs);
    m_motorShooterLeft.Config_kI(ShooterConstants::kSensorId, 0.0, kTimeoutMs);
    m_motorShooterLeft.Config_kD(ShooterConstants::kSensorId, 0.0, kTimeoutMs);

    m_motorShooterRight.ConfigFactoryDefault();
    /* first choose the sensor */
    m_motorShooterRight.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, ShooterConstants::kSensorId, kTimeoutMs);
    m_motorShooterRight.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    m_motorShooterRight.ConfigNominalOutputForward(0, kTimeoutMs);
    m_motorShooterRight.ConfigNominalOutputReverse(0, kTimeoutMs);
    m_motorShooterRight.ConfigPeakOutputForward(1, kTimeoutMs);
    m_motorShooterRight.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    m_motorShooterRight.Config_kF(ShooterConstants::kSensorId, F, kTimeoutMs);
    m_motorShooterRight.Config_kP(ShooterConstants::kSensorId, P, kTimeoutMs);
    m_motorShooterRight.Config_kI(ShooterConstants::kSensorId, 0.0, kTimeoutMs);
    m_motorShooterRight.Config_kD(ShooterConstants::kSensorId, 0.0, kTimeoutMs);


}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {
    if ( 0 )
    {
        //std::cout << "angle " << GetRotationDegreeA() << " " << GetRotationDegreeB() << "\n";
        std::cout << "shoot " << 
        m_motorShooterLeft.GetMotorOutputPercent() << " " << 
        m_motorShooterLeft.GetSelectedSensorVelocity( ShooterConstants::kSensorId ) << " " << " " << 
        m_motorShooterRight.GetMotorOutputPercent() << " " << 
        m_motorShooterRight.GetSelectedSensorVelocity( ShooterConstants::kSensorId ) << "\n";
    }
}


void ShooterSubsystem::SpinupShooter() {

    m_motorShooterLeft.Set(  
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
        //ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //-1.0
    );
    m_motorShooterRight.Set(
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
        //ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //1.0
    );
}


void ShooterSubsystem::SpindownShooter() {
    m_motorShooterLeft.NeutralOutput( );
    m_motorShooterRight.NeutralOutput( );
}

double ShooterSubsystem::GetMaxAngle()
{
    return 2.7;
}

double ShooterSubsystem::GetMinAngle()
{
    return 2.19;
}

void ShooterSubsystem::AngleShooterUp() 
{
    std::cout << "AngleShooterUp" << GetRotationDegreeB() << "\n";
    if ( GetRotationDegreeB() < GetMaxAngle() ) 
    {
        m_motorAngle.Set( -0.8 );
    }
    else
    {
        StopShooterAngle();
    }
    
}

void ShooterSubsystem::AngleShooterDown() 
{
    std::cout << "AngleShooterDown" << GetRotationDegreeB() << "\n";
    if ( GetRotationDegreeB() > GetMinAngle() )
    {
        m_motorAngle.Set( 0.8 );
    }
    else
    {
        StopShooterAngle();
    }
    
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
    double const positionRatio = 0.6 * ( cameraValueMax - cameraValue ) / cameraValueMax;
    double const angleRange = GetMaxAngle() - GetMinAngle();
    return GetMinAngle() + 0.12 + angleRange * positionRatio;
}



void ShooterSubsystem::TiltToAngle( double angle ) {
    if ( GetRotationDegreeB() < ( angle - 0.005) )
    {
        AngleShooterUp();
    }
    else if (  GetRotationDegreeB() > ( angle + 0.005) )
    {
        AngleShooterDown();
    }
    else
    {
        StopShooterAngle();
    }
}



void ShooterSubsystem::TiltToTarget() {
   extern nt::NetworkTableEntry yEntry;
   double const yVal = yEntry.GetDouble( -1.0 );
   if ( yVal > 0 )
   {
    double const angle = CalculateTargetAngleFromCameraValue( yVal );
    std::cout << "yVal: " << yVal << " " << angle << "\n";

    TiltToAngle( angle );
   }
}



