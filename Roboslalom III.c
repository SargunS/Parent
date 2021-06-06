#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  leftTouch,      sensorTouch)
#pragma config(Sensor, dgtl7,  rightTouch,     sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, I2C_1,  rightIME,       sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  leftIME,        sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, PIDControl, driveRight, encoderPort, I2C_1)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex269_MC29, PIDControl, reversed, driveLeft, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/****************************************************
Name: Sargun Singh
Period: 5
Date:
Assignment: Roboslalom III - 2 Sensors
Program Description: Follow the black line until the end.
Algorithm:
1.
************************************************************************/
//Variables
int threshold = 712;
//Functions
void goStraight();
void goRight();
void goLeft();
//----------------------------------------------------------------------
task main()
{
while (true)
{
	goStraight();
  goRight();
  goLeft();
  goStraight();
  goLeft();
}
}

//Function Glossary **************************************************************************************
void goStraight()
  {
if (SensorValue[leftLineFollower]>threshold && SensorValue[centerLineFollower]>threshold)
		motor[rightMotor] = 63;
    motor[leftMotor] = 63;
  }

void goRight()
  {
if (SensorValue[leftLineFollower]<threshold && SensorValue[centerLineFollower]>threshold)
  	motor[rightMotor] = 0;
    motor[leftMotor] = 63;
  }

void goLeft()
  {
if (SensorValue[leftLineFollower]>threshold && SensorValue[centerLineFollower]<threshold)
  	motor[rightMotor] = 63;
    motor[leftMotor] = 0;
  }
