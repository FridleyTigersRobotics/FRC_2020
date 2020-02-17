/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <stdio.h>

#include <frc/PWMVictorSPX.h>
#include <Constants.h>

#include <subsystems/ControlPanelSubsystem.h>

ControlPanelSubsystem::ControlPanelSubsystem():
   m_liftMotor      { Controlpanelconstants::kControlPanelLiftMotorCanId },
   m_spinMotor      { Controlpanelconstants::kControlPanelSpinMotorCanId },
   m_topLimitSwitch { Controlpanelconstants::kIntakeTopLimitDioPort },
   m_botLimitSwitch { Controlpanelconstants::kIntakeBotLimitDioPort },
   m_colorSensor    { Controlpanelconstants::i2cPort }
{

}


void ControlPanelSubsystem::LiftControlPanelArm() 
{
    double extendMotorSpeed = 0.0;
    if ( IsTopLimitEngaged() == false )
    {
        extendMotorSpeed = 1.0;
    } 
    frc::Color detectedColor = m_colorSensor.GetColor();

    std::cout << "color: " << detectedColor.red << " " << detectedColor.green << " " <<  detectedColor.blue << "\n";

    m_liftMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, extendMotorSpeed );
}

void ControlPanelSubsystem::LowerControlPanelArm() 
{
    double extendMotorSpeed = 0.0;
    if ( IsBotLimitEngaged() == false )
    {
        extendMotorSpeed = -1.0;
    }
    m_liftMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, extendMotorSpeed );
}


bool ControlPanelSubsystem::IsTopLimitEngaged() 
{
    return m_topLimitSwitch.Get();
}   

bool ControlPanelSubsystem::IsBotLimitEngaged() 
{
    return m_botLimitSwitch.Get();
}   

void ControlPanelSubsystem::StopLift()
{
    double extendMotorSpeed = 0.0;
    m_liftMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, extendMotorSpeed );
}


void ControlPanelSubsystem::StartSpinning()
{
    double extendMotorSpeed = 0.5;
    m_spinMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, extendMotorSpeed );
}


void ControlPanelSubsystem::StopSpinning()
{
    double extendMotorSpeed = 0.0;
    m_spinMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, extendMotorSpeed );
}


// This method will be called once per scheduler run
void ControlPanelSubsystem::Periodic() { }
