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
    m_topLimitSwitch   { IntakeConstants::kIntakeTopLimitDioPort },
    m_botLimitSwitch   { IntakeConstants::kIntakeBotLimitDioPort }
{
    m_engageIntake = false;
}

// This method will be called once per scheduler run
void IntakeSubsystem::Periodic() 
{

}

void IntakeSubsystem::StartIntake() {
    m_motorIntakeRotate.Set( 0.3 );
}

void IntakeSubsystem::StopIntake() {
    m_motorIntakeRotate.Set( 0.0 );
}   


void IntakeSubsystem::LowerIntake() 
{
    double extendMotorSpeed = 0.0;
    if ( IsBotLimitEngaged() == false )
    {
        extendMotorSpeed = -0.5;
    }
    m_motorIntakeExtend.Set( extendMotorSpeed );
}

void IntakeSubsystem::RaiseIntake() 
{
    double extendMotorSpeed = 0.0;

    if ( IsTopLimitEngaged() == false )
    {
        extendMotorSpeed = 0.5;
    } 
    m_motorIntakeExtend.Set( extendMotorSpeed );
}   

void IntakeSubsystem::MoveIntake()
{
    double extendMotorSpeed = 0.0;

    if ( m_engageIntake == true )
    {

    }
    else
    {

    }

}



bool IntakeSubsystem::IsTopLimitEngaged() 
{
    return m_topLimitSwitch.Get();
}   

bool IntakeSubsystem::IsBotLimitEngaged() 
{
    return m_botLimitSwitch.Get();
}   

