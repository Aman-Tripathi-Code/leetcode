// Last updated: 1/11/2026, 1:02:18 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
    }
};