// Last updated: 1/11/2026, 1:00:09 PM
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 1, hi = 2001;
        while(hi - lo > 1){
            int mid = lo + (hi - lo)/2;
            int ub = lower_bound(arr.begin(),arr.end(),mid) - arr.begin();
            if(mid - ub <= k) lo = mid;
            else hi = mid; 
        }
        return lo;
    }
};