// Last updated: 1/11/2026, 12:59:50 PM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = -1, mini = nums[0];
        for(auto &it: nums){
            if(it > mini){
                ans = max(ans,(it-mini));
            }
            else mini = it;
        }
        return ans;
    }
};