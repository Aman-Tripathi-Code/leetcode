// Last updated: 3/29/2026, 12:14:57 AM
1class Solution {
2public:
3    int reverse(int x) {
4        int rev = 0;
5        while(x){
6            int rem = x % 10;
7            if(rev > 214748364 || (rev == 214748364 && rem > 7)) return 0;
8            if(rev < -214748364 || (rev == -214748364 && rem > 8)) return 0;
9            rev = 10 * rev + rem;
10            x /= 10;
11        }
12        return rev;
13    }
14};