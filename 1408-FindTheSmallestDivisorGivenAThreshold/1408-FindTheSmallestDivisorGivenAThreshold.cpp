// Last updated: 1/11/2026, 1:00:30 PM
class Solution {
public:
    bool check(int x, vector<int>& nums, int threshold){
        long long cnt = 0;
        for(auto num: nums){
            cnt += (num + x - 1)/x;
        }
        return cnt <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int lo = 1, hi = *max_element(nums.begin(),nums.end()), ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid, nums, threshold)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};