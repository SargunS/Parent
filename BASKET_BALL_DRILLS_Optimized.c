#pragma config(StandardModel, "RVW SWERVEBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/****************************************************
Name: Sargun Singh
Period: 5
Date: 3/18/20
Assignment: Basketball Drills
Program Description: bot goes forward until it sees a line, goes back to the start, and repeats this for three lines, each one farther than the one before.
Algorithm:
1. forward until first line.
2. back to start.
3. forward until second line.
4. back to start.
5. forward until third line.
6. back to start.
7. stop robot.
************************************************************************/
//Variables
int thresholdValue = 1691; //This is the average of the values sensed over light and dark surfaces.
int FirstLineEncoderValue = 460; //The encoder value to go to the first line is 460.
//Functions
void findLine(); //This function tells bot to find the line.
void findLight(); //This function tells the bot to look for a light surface.
void goBackEncoder(int FirstLineEncoderValue); //This function tells the bot to go back to the start.
void findFirstLine(); //This function tells the robot to find the first line.
void findSecondLine(); //This function tells the robot to find the second line.
void findThirdLine(); //This function tells the robot to find the third line.
//----------------------------------------------------------------------

task main()
{
	findFirstLine(); //go to the first line
	goBackEncoder(FirstLineEncoderValue*1); // go back to base
	findSecondLine(); //go to the second line
	goBackEncoder(FirstLineEncoderValue*4); // go back to base
	findThirdLine(); //go to the third line
	goBackEncoder(FirstLineEncoderValue*6); // back to base
}
// Function Glossary############################################################

void findFirstLine()                      //This function will tell the bot to go to the first line.
{
	findLine();							              	// find first line
}
void findSecondLine()                     //This function will tell the bot to go to the second line.
{
	findLine();							              	// find first line again to go to second line
	findLight();						              	// find lighter surface after first line
	findLine();							              	// find second line
}
void findThirdLine()                      //This function will tell the bot to go to the third line.
{
	findLine();						  	              // find first line to go to third line
	findLight();							              // find lighter surface after the first line
	findLine();								              // find second line
	findLight();							              // find lighter surface after second line
	findLine();								              // find third line
}

void findLine() //This function tells robot to stop when it sees a line.
{
while(SensorValue(leftLineFollower)<thresholdValue) //The bot performs the function as long as the left line follower reads a value that is less than the threshold.
{
  motor[rightMotor] = 127; //This tells the right motor to run forward at full power as long as the while statement is true.
  motor[leftMotor] = 127; //This tells the left motor to run forward at full power as long as the while statement is true.
  sleep(1); //bot sleeps for one second
}
}

void findLight() //This function tells the robot to keep moving forward once it sees a line.
{
while(SensorValue(leftLineFollower)>=thresholdValue) //Tells bot to perform function when following if statement is true.
{
	 motor[rightMotor] = 127; //This tells the right motor to run forward at full power as long as the if statement above is true.
   motor[leftMotor] = 127; //This tells the left motor to run forward at full power as long as the if statement above is true.
}
}

void goBackEncoder(int FirstLineEncoderValue)
{
  SensorValue[leftEncoder] = 0; //reset encoder
  while(SensorValue[leftEncoder] > -FirstLineEncoderValue) //perform the function of going backward only while the value of the left encoder is greater than
  {
    motor[leftMotor] = -127;  //left motor goes backward at full power as long as the while statement above is true.
    motor[rightMotor] = -127; //right motor goes backward at full power as long as the while statement above is true.
  }
  motor[leftMotor] = 0; //stop the left motor after completing the function to go back.
  motor[rightMotor] = 0; //stop the right motor after completing the function to go back.
}