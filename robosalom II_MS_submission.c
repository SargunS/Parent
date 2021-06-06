#pragma config(StandardModel, "RVW Buggybot")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Variables
int threshold = 2019; //The value of the threshold is 2019
//Functions
void followLine(); //This function tells the bot to follow the line
//----------------------------------------------------------------------
task main()
{
while(true) //Repeat the following instructions in a forever loop
	{
   followLine(); //This function tells the bot to follow the line
  }
}

// Function Glossary############################################################
void followLine() //This function tells the bot to follow the line
{
if (SensorValue[lightSensor] <= threshold) //perform the following instructions if the light sensor reads a value that is less than or equal to the threshold
{
	motor[leftMotor] = 112; //the left motor is set to run at the power level of 112
	motor[rightMotor] = 1; //the right motor is set to run at the power level of 1
}
else //when the light sensor does not read a value less than or equal to the threshold, then perform the following instructions
{
motor[leftMotor] = 1; //the left motor is set to run at the power level of 1
motor[rightMotor] = 112; //the right motor is set to run at the power level of 112
}
}
