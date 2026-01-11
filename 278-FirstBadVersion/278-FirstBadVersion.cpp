// Last updated: 1/11/2026, 1:02:07 PM
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while(hi > lo + 1){
            int mid = lo + (hi - lo)/2;
            if(!isBadVersion(mid)){
                lo = mid;
            }
            else hi = mid;
        }
        return hi;
    }
};