#include <cmath>
int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
    //the main idea is at some day, the upSpeed of that day will compensate for the rest instead of n more day cycles
    //if each day a tree grows d Height then it would take desiredHeight/d days
    // +1 is because of day 1 is the 1st day
    double d = upSpeed - downSpeed;
    return (upSpeed >= desiredHeight ? 0 : ceil((desiredHeight - upSpeed)/d)) + 1; 
}