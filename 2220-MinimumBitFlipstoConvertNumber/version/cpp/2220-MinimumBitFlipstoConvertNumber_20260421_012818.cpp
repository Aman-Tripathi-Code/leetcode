// Last updated: 4/21/2026, 1:28:18 AM
1class Solution {
2public:
3    int minBitFlips(int start, int goal) {
4        int xr = start ^ goal;
5        return __builtin_popcount(xr);
6    }
7};