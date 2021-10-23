// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>
#include <memory>

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
  std::unique_ptr<WPI_TalonFX> mLeftLeader;
  std::unique_ptr<WPI_TalonFX> mLeftFollower;
  std::unique_ptr<WPI_TalonFX> mRightLeader;
  std::unique_ptr<WPI_TalonFX> mRightFollower;
  const double cpr = 2048.0 * 5;

};
