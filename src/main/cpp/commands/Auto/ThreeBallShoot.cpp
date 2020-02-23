/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/DriveSubsystem.h>

#include "commands/Auto/ThreeBallShoot.h"
#include "commands/RotateAngle.h"
#include "commands/DriveForTime.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ThreeBallShoot::ThreeBallShoot( DriveSubsystem *driveSubsystem ) {
  AddCommands(
    RotateAngle( 90, driveSubsystem ),
    DriveForTime( 3.0, driveSubsystem ),
    RotateAngle( -90, driveSubsystem )
  );

}
