// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <ctre/Phoenix.h>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  WPI_TalonFX mLeftLeader{20};
  WPI_TalonFX mLeftFollower{21};
  WPI_TalonFX mRightLeader{22};
  WPI_TalonFX mRightFollower{23};
  const double cpr = 2048.0 * 5;

};
