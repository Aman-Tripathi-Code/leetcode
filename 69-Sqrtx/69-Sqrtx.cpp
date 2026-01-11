// Last updated: 1/11/2026, 1:03:38 PM
class Solution {

public:
    int mySqrt(int x) {
        if(!x){
            return 0;
        }
        if(x==1){
            return 1;
        }
        int lo = 1, hi = x;
        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;
            if(mid<=x/mid){
                lo = mid;
            }
            else hi = mid;
        }
        return lo;
    }
};