// Last updated: 5/18/2026, 2:12:04 PM
1class Solution {
2public:
3    int numberOfMatches(int n) {
4        int cnt = 0;
5        while(n>1){
6            int rem = n % 2;
7            cnt += n/2 + rem;
8            n /= 2;
9        }
10        return cnt;
11    }
12};