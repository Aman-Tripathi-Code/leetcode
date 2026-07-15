// Last updated: 7/15/2026, 1:00:26 PM
1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        int oddSum = 0, evenSum = 0;
5        for(int i = 1; i<=2*n; i++){
6            if(i & 1) oddSum += i;
7            else evenSum += i;
8        }
9        return __gcd(oddSum,evenSum);
10    }
11};