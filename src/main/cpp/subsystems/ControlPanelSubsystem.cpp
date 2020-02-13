/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "Constants.h"
#include "subsystems/ControlPanelSubsystem.h"
#include <frc/PWMVictorSPX.h>
#include "Robot.h"

ControlPanelSubsystem::ControlPanelSubsystem():
//m_Controllift {1, Controlpanelconstants::kControlpanelliftport},
m_Controlmotor {Controlpanelconstants::kControlpanelmotorport}
{}


void ControlPanelSubsystem::LiftControlPanelArm() {
    std::cout << "LiftControlPanelArm\n";
//m_Controllift.Set(true);
}

void ControlPanelSubsystem::LowerControlPanelArm() {
    std::cout << "LowerControlPanelArm\n";
//m_Controllift.Set(false);
}




// This method will be called once per scheduler run
void ControlPanelSubsystem::Periodic() {}
