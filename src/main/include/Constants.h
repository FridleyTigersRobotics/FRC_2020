/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
constexpr int kLeftMotor1Port = 0;
constexpr int kLeftMotor2Port = 1;
constexpr int kRightMotor1Port = 2;
constexpr int kRightMotor2Port = 3;
}

namespace ShooterConstants {
constexpr int kLeftMotorCanId  = 0;
constexpr int kRightMotorCanId = 1;
constexpr int kjda = 0; //analog input channel A for John Deere rotation sensor
constexpr int kjdb = 1; //analog input channel B for John Deere rotation sensor
constexpr double kDistPerRotation = 360;  //how far the nechanism travels in 1 rotation of the encoder in angular degrees

constexpr int kLoaderMotorPwmId = 5;
constexpr int kSensorId         = 0;


constexpr float ShooterRpmTarget = 500.0f;
constexpr float ShooterRpmMin    = 480.0f;
constexpr float ShooterRpmMax    = 520.0f;

}  // namespace ShooterConstants

namespace IntakeConstants {
constexpr int kIntakeRotateMotorPwmId = 6;
constexpr int kIntakeExtendMotorPwmId = 7;
}  // namespace IntakeConstants

namespace DriverStationConstants {
constexpr int kDriverControllerPort = 0;
}  // namespace DriverStationConstants
