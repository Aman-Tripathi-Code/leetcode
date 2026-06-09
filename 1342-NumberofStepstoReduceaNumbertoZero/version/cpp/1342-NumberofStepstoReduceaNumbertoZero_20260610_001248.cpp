// Last updated: 6/10/2026, 12:12:48 AM
1class Solution {
2public:
3    int numberOfSteps(int num) {
4        int msb = 0, setBits = 0;
5        for(int i = 0; i<22; i++){
6            if(num & (1 << i)){
7                msb = i;
8                setBits++;
9            }
10        }
11        return msb  + setBits;
12    }
13};