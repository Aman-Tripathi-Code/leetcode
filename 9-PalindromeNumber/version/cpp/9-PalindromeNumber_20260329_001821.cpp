// Last updated: 3/29/2026, 12:18:21 AM
1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x < 0) return false;
5        int rev = 0, num = x;
6        while(x){
7            int rem = x % 10;
8            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && rem > 7)) return false;
9            rev = 10 * rev + rem;
10            x /= 10;
11        }
12        return num == rev;
13    }
14};