/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>
#include "subsystems/IndexerSubsystem.h"

class ToggleIndexerReverse
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 ToggleIndexerReverse> {
 public:
  ToggleIndexerReverse( IndexerSubsystem* subsystem );

  void Initialize() override;

 private:
  IndexerSubsystem* m_IndexerSubsystem;
  bool indexerRotating;
};
