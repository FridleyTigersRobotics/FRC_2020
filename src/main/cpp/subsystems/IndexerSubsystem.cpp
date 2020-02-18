/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "Constants.h"
#include "subsystems/IndexerSubsystem.h"
#include <ctre/Phoenix.h>
#include <stdio.h>


int count;
int long setPoint;
int long long ballCounter;

IndexerSubsystem::IndexerSubsystem():
    m_conveyorMotor      { IndexerSubsystemConstants::kIndexerMotorCanId },
    m_motorShooterLoader {  ShooterConstants::kLoaderMotorCanId },
    m_ballDetector       { 4 },
    m_timer              {},
    m_conveyorEncoder    {5,6}
{
    //frc::Encoder  m_conveyorEncoder{0,1};
    m_state = 0;
    m_checkedBall = false;
    count = 0;
    setPoint = 0;
    ballCounter = 0;

    m_conveyorEncoder.SetMaxPeriod(1);
    m_conveyorEncoder.SetMinRate(1);
    m_conveyorEncoder.SetDistancePerPulse(0.1);
    m_conveyorEncoder.SetReverseDirection(false);
    m_conveyorEncoder.SetSamplesToAverage(2);
    m_conveyorEncoder.Reset();
    m_timer.Reset();
    m_timer.Start();
    //double time = timer.Get();
}



// This method will be called once per scheduler run
void IndexerSubsystem::Periodic() 
{
    {
        count++;

        if ( count > 100 )
        {
            //std::cout << "ball: " << m_ballDetector.Get() << "\n";
            std::cout << "m_conveyorEncoder: " << m_ballDetector.Get() << " " << m_conveyorEncoder.Get() << " " << m_conveyorEncoder.GetRaw() <<  " " << m_conveyorEncoder.GetDistance() << "\n";
            count = 0;
        }
    }
    
    //std::cout << "Periodic\n";
}


void IndexerSubsystem::InitIndexer() {
    m_timer.Reset();
    m_timer.Start();
    m_state = 0;
}

void IndexerSubsystem::StartIndexer() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.4 );
    //m_motorShooterLoader.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -1.0 );
}

void IndexerSubsystem::StopIndexer() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0 );
    //m_motorShooterLoader.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.0 );
}

void IndexerSubsystem::StartIndexerReverse() {
    m_conveyorMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -0.4 );
    //m_motorShooterLoader.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 1.0 );
}







void IndexerSubsystem::GetBalls()
{
    bool const kUseTime = false;
    double time = m_timer.Get();
    int long encoderValue = m_conveyorEncoder.GetDistance();
    int long encoderDiff  = encoderValue - setPoint;

    if ( m_state == 0 || m_state == 1 )
    {
        if ( m_state == 0 )
        {
            if (encoderDiff < 1500 ) //( time < 0.5 )
            {
                StartIndexer();
            }
            else
            {
                m_state = 1;
                if ( kUseTime )
                {
                    m_timer.Reset();
                    m_timer.Start();
                }
                else
                {
                    setPoint = encoderValue;
                    //m_conveyorEncoder.Reset();
                }
                m_checkedBall = false;
            }
        }
        else if ( m_state == 1)
        {
            if (encoderDiff > -1500 ) //( time < 1.0 )
            {
                #if 1
                if ( ( m_checkedBall == false ) &&
                    ( m_ballDetector.Get() > 0 ) )
                {
                    m_state = 2;
                    if ( kUseTime )
                    {
                        m_timer.Reset();
                        m_timer.Start();
                    }
                    else
                    {
                        setPoint = encoderValue;
                        //m_conveyorEncoder.Reset();
                    }
                    m_checkedBall = false;
                }
                else
                #endif
                {
                    StartIndexerReverse();
                }
                m_checkedBall = true;
            }
            else
            {
                m_state = 0;
                if ( kUseTime )
                {
                    m_timer.Reset();
                    m_timer.Start();
                }
                else
                {
                    setPoint = encoderValue;
                    //m_conveyorEncoder.Reset();
                }
                m_checkedBall = false;
            }

        }
    }
    else if ( m_state == 2 )
    {
        if  (encoderValue < 1500 ) //( time < 0.5 )
        {
            StartIndexer();
        }
        else
        {
            m_state = 0;
            if ( kUseTime )
            {
                m_timer.Reset();
                m_timer.Start();
            }
            else
            {
                setPoint = encoderValue;
                m_conveyorEncoder.Reset();
            }

            m_checkedBall = false;
        }
    }
}

