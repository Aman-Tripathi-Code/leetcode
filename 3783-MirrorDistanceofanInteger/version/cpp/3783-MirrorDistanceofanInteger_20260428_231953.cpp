// Last updated: 4/28/2026, 11:19:53 PM
1class Solution {
2public:
3    int reverse(int n){
4        int rev = 0;
5        while(n){
6            int rem = n % 10;
7            rev = 10 * rev + rem;
8            n /= 10;
9        }
10        return rev;
11    }
12    int mirrorDistance(int n) {
13        int rev = reverse(n);
14        return abs(n - rev);
15    }
16};