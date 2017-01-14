#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int randNuber(int angle);
int reflection(int angle);

int kickDisc(double wallWidth,double wallHeight,double ballCenterX,
	double kickAngle,double ballRadius,double goalWidth);	

int recurtion(double leftToTop,double ballRightX,double ballLeftX,double ballCenterX,
	double goalRightX,double goalLeftX,double angle,double wallWidth,double x);

double movedAlongY(double angle,double x);

int main (void)
{
	printf("Returned: %d\n",kickDisc(10,26,2,33,1,2));

	return 0;
}

int kickDisc(double wallWidth,double wallHeight,double ballCenterX,
	double kickAngle,double ballRadius,double goalWidth)
{
	/*goal's left and right coordinates*/
	double goalLeftX,goalRightX;
	/*ball's left and rigth side coordinates*/
	double ballLeftX,ballRightX;

	/*gaol's left and right coordinates*/
	goalLeftX=(wallWidth/2)-(goalWidth/2);
	goalRightX=(wallWidth/2)+(goalWidth/2);

	/*ball's left and rigth side coordinates*/
	ballLeftX=ballCenterX-ballRadius;
	ballRightX=ballCenterX+ballRadius;

	/*checks whether any of arguments is negative or 0*/
	if(wallWidth<=0 || wallHeight<=0 || ballCenterX<=0 || ballRadius<=0 || goalWidth<=0 )
	{
		return 0;
	}

	/*checks if the anlge is within the condition range*/
	if(kickAngle<5 || kickAngle>175)
	{
		return 0;
	}

	/*compares sizes of the table and ball*/
	if(wallWidth<ballRadius*2 || wallHeight<ballRadius*2)
	{
		return 0;
	}

	/*if the ball's initial location is incorrect*/
	if(ballCenterX<ballRadius ||  ballRightX>wallWidth)
	{
		return 0;
	}

	/*if the goal is wider then table*/
	if(goalWidth>wallWidth)
	{
		return 0;
	}

	/* if the angle is 90 degrees and the ball is within the range of goal's width*/
	if(kickAngle==90 && ((ballCenterX>=goalLeftX && ballCenterX<=goalRightX)||
		(ballCenterX<=goalRightX && ballCenterX>=goalLeftX)))
	{
		return 1;
	}
	/* if the angle is 90 degrees but the ball isn't within the range*/
	else if(kickAngle==90)
	{
		return 0;
	}
	/* if the kick is with angle 5<=a<=175 */
	else
	{
		/*call to the recursive funtion(last parameter is stepsize)*/
		/*distance to the top is taken as wallHeight-ballRadius*/
		return(recurtion(wallHeight-ballRadius,ballRightX,ballLeftX,ballCenterX,
		 goalRightX,goalLeftX,kickAngle,wallWidth,0.01));
	}

	return 0;
}

int recurtion(double leftToTop,double ballRightX,double ballLeftX,double ballCenterX,
	double goalRightX,double goalLeftX,double angle,double wallWidth,double x)
{
	int ans=1;
	double movedY=0;

	/*reflection angle is smaller then 5*/
	if(angle<5)
	{
		angle=5;
	}

	/*reflection angle is bigger then 175*/
	if(angle>175)
	{
		angle=175;
	}

	/* terminating condition*/
	/* terminates when top of the table is reached*/
	if (!(leftToTop>0))
	{
		printf("Hits the top 1)ballLeftX=%.2f 2)ballRightX=%.2f 3)ballCenterX=%.2f"
			" 4)leftToTop=%.2f \n",ballLeftX,ballRightX,ballCenterX,leftToTop);

		/*checks if the ball is in the goal */
		if((ballCenterX>=goalLeftX && ballCenterX<=goalRightX)||
		(ballCenterX<=goalRightX && ballCenterX>=goalLeftX))
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
	}
	/*ball moves to the right */
	else if(angle<90)
	{
		if(ballRightX<wallWidth)
		{
			movedY=movedAlongY(angle,x);

			ans*=recurtion(leftToTop-fabs(movedY),ballRightX+x,ballLeftX+x,ballCenterX+x,
				goalRightX,goalLeftX,angle,wallWidth,x);
		}
		/*ball hits right side of the table */
		else
		{
			printf("hits right side: 1)ballLeftX=%.2f 2)ballRightX=%.2f 3)ballCenterX=%.2f"
			" 4)leftToTop=%.2f \n",ballLeftX,ballRightX,ballCenterX,leftToTop);

			ans*=recurtion(leftToTop-movedY,ballRightX,ballLeftX,ballCenterX,
				goalRightX,goalLeftX,reflection(angle),wallWidth,x);
		}
	}
	else
	{
		/*ball moves to the left*/
		if(ballLeftX>0)
		{
			movedY=movedAlongY(180-angle,x);

			ans*=recurtion(leftToTop-fabs(movedY),ballRightX-x,ballLeftX-x,ballCenterX-x,
			goalRightX,goalLeftX,angle,wallWidth,x);
		}
		/*ball hits left side of the table*/
		else
		{	
			printf("hits left side: 1)ballLeftX=%.2f 2)ballRightX=%.2f 3)ballCenterX=%.2f"
			" 4)leftToTop=%.2f \n",ballLeftX,ballRightX,ballCenterX,leftToTop);

			ans*=recurtion(leftToTop-movedY,ballRightX,ballLeftX,ballCenterX,
			goalRightX,goalLeftX,reflection(angle),wallWidth,x);
		}
	}

	return ans;

}

double movedAlongY(double angle,double x)
{	
	/*returns the distance moved alog y axis for x value*/
	/*angle is converted to radians*/
	return(tan(angle*3.14/180)*x);
}

int randNumber(int angle)
{
	srand(angle);

	return rand();
}

int reflection(int angle)
{
	int randomDiversion;

	randomDiversion=randNumber(angle);

	/*generates a randomDivertion between -5 and 5 degrees */
	while (!(randomDiversion<=5 && randomDiversion>=-5))
	{
		randomDiversion=(randomDiversion+1)/-3;
	} 

	printf("randomDiversion is: %d\n",randomDiversion );

	angle+=randomDiversion;

	printf("reflected with angle: %d\n",180-angle );

	return (180-angle);
}