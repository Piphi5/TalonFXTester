// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>



#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  mLeftLeader = std::make_unique<WPI_TalonFX>(20);
  mLeftFollower = std::make_unique<WPI_TalonFX>(21);
  mRightLeader = std::make_unique<WPI_TalonFX>(22);
  mRightFollower = std::make_unique<WPI_TalonFX>(23);

  mLeftLeader->ConfigFactoryDefault();
  mLeftLeader->SetInverted(true);
  mLeftLeader->SetNeutralMode(motorcontrol::NeutralMode::Brake);

  mLeftFollower->ConfigFactoryDefault();
  mLeftFollower->SetInverted(true);
  mLeftFollower->SetNeutralMode(motorcontrol::NeutralMode::Brake);
  
  mLeftLeader->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
  mLeftLeader->SetSensorPhase(true);
  mLeftLeader->ConfigVelocityMeasurementWindow(5);
  mLeftLeader->ConfigVelocityMeasurementPeriod(motorcontrol::VelocityMeasPeriod::Period_100Ms);

  mRightLeader->ConfigFactoryDefault();
  mRightLeader->SetInverted(false);
  mRightLeader->SetNeutralMode(motorcontrol::NeutralMode::Brake);

  mRightFollower->ConfigFactoryDefault();
  mRightFollower->SetInverted(false);
  mRightFollower->SetNeutralMode(motorcontrol::NeutralMode::Brake);
  
  mRightLeader->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
  mRightLeader->SetSensorPhase(false);
  mRightLeader->ConfigVelocityMeasurementWindow(5);
  mRightLeader->ConfigVelocityMeasurementPeriod(motorcontrol::VelocityMeasPeriod::Period_100Ms);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  frc::SmartDashboard::PutNumber("Left Position", mLeftLeader->GetSelectedSensorPosition() / cpr);
  frc::SmartDashboard::PutNumber("Left Rate", mLeftLeader->GetSelectedSensorVelocity() / cpr / 0.1);

  frc::SmartDashboard::PutNumber("Right Position", mRightLeader->GetSelectedSensorPosition() / cpr);
  frc::SmartDashboard::PutNumber("Right Rate", mRightLeader->GetSelectedSensorVelocity() / cpr / 0.1);

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
