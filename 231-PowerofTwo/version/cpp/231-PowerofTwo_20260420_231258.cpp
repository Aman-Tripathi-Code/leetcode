// Last updated: 4/20/2026, 11:12:58 PM
1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        if(n<=0) return false;
5        return !(n&(n-1));
6    }
7};