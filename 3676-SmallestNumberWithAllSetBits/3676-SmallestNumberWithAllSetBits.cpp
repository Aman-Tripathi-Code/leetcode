// Last updated: 1/11/2026, 12:59:14 PM
class Solution {
public:
    int smallestNumber(int n) {
        int x = log2(n);
        return pow(2,x+1)-1;
    }
};