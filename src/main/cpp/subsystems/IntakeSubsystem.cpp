/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Constants.h>
#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() :
    m_motorIntakeRotate{ IntakeConstants::kIntakeRotateMotorPwmId },
    m_motorIntakeExtend{ IntakeConstants::kIntakeExtendMotorPwmId },
    m_topLimitSwitch   { IntakeConstants::kIntakeTopLimitAnalogPort },
    m_botLimitSwitch   { IntakeConstants::kIntakeTopLimitAnalogPort }
{
    m_engageIntake = false;
}

// This method will be called once per scheduler run
void IntakeSubsystem::Periodic() 
{
    double extendMotorSpeed = 0.0;

    if ( m_engageIntake == true )
    {
        if ( IsBotLimitEngaged() == false )
        {
            extendMotorSpeed = -0.5;
        }
    }
    else
    {
        if ( IsTopLimitEngaged() == false )
        {
            extendMotorSpeed = 0.5;
        } 
    }

    m_motorIntakeExtend.Set( extendMotorSpeed );
}

void IntakeSubsystem::StartIntake() {
    m_motorIntakeRotate.Set( 0.3 );
}

void IntakeSubsystem::StopIntake() {
    m_motorIntakeRotate.Set( 0.0 );
}   


void IntakeSubsystem::LowerIntake() {
    m_engageIntake = true;
}

void IntakeSubsystem::RaiseIntake() {
    m_engageIntake = false;
}   



bool IntakeSubsystem::IsTopLimitEngaged() 
{
    return m_topLimitSwitch.GetValue() > 0.5 ? true : false;
}   

bool IntakeSubsystem::IsBotLimitEngaged() 
{
    return m_botLimitSwitch.GetValue() > 0.5 ? true : false;
}   

