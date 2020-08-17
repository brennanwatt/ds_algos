#include <stdio.h>

#define TOTAL_DEGREES   (360)

void findAngle(int hour, int minute)
{
    int minuteAngle = TOTAL_DEGREES * minute / 60;
    int hourAngle = (TOTAL_DEGREES * hour / 12) + ((TOTAL_DEGREES/12) * minute / 60);
    
    int angleDiff;
    if (hourAngle > minuteAngle)
    {
        angleDiff = hourAngle - minuteAngle;
    }
    else
    {
        angleDiff = minuteAngle - hourAngle;
    }
    
    if (angleDiff > 180)
    {
        angleDiff = 360 - angleDiff;
    }
    
    printf("Angle difference = %d degrees\n",angleDiff);
}

// Find angle between hour and minute
int main()
{
	int hour = 5;
    int minute = 30;
	findAngle(hour, minute);

	return 0;
}