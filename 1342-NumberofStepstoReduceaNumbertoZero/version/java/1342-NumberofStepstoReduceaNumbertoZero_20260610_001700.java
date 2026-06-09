// Last updated: 6/10/2026, 12:17:00 AM
1class Solution {
2    public int numberOfSteps(int num) {
3        int msb = 0, setBits = 0;
4        for(int i = 0; i<22; i++){
5            if((num & (1 << i)) > 0){
6                msb = i;
7                setBits++;
8            }
9        }
10        return msb + setBits;
11    }
12}