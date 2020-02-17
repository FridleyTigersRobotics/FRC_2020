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
   m_liftMotor { Controlpanelconstants::kControlPanelLiftMotorPwmPort },
   m_spinMotor { Controlpanelconstants::kControlPanelSpinMotorCanId },
   m_topLimitSwitch   { Controlpanelconstants::kIntakeTopLimitDioPort },
   m_botLimitSwitch   { Controlpanelconstants::kIntakeBotLimitDioPort }
{
    
}


void ControlPanelSubsystem::LiftControlPanelArm() 
{
    double extendMotorSpeed = 0.0;
    if ( IsTopLimitEngaged() == false )
    {
        extendMotorSpeed = -1.0;
    } 
    m_liftMotor.Set( extendMotorSpeed );
}

void ControlPanelSubsystem::LowerControlPanelArm() 
{
    double extendMotorSpeed = 0.0;
    if ( IsBotLimitEngaged() == false )
    {
        extendMotorSpeed = 1.0;
    }
    m_liftMotor.Set( extendMotorSpeed );
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
    m_liftMotor.Set( extendMotorSpeed );
}

// This method will be called once per scheduler run
void ControlPanelSubsystem::Periodic() { }
