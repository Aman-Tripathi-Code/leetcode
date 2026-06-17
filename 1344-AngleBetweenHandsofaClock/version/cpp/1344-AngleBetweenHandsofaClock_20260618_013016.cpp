// Last updated: 6/18/2026, 1:30:16 AM
1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double angle = 0.0;
5        double hourAngle = (hour%12 * 30) + (minutes/2.0);
6        double minutesAngle = 6.0 * minutes;
7        angle = abs(hourAngle - minutesAngle);
8        return min(angle,360-angle);
9    }
10};