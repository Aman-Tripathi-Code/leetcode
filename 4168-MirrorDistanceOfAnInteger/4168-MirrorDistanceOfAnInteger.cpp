// Last updated: 6/8/2026, 2:07:25 AM
class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n){
            int rem = n % 10;
            rev = 10 * rev + rem;
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int rev = reverse(n);
        return abs(n - rev);
    }
};