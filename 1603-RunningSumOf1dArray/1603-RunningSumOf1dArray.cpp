// Last updated: 1/11/2026, 1:00:15 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // int n = nums.size();
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for(int i = 1; i<nums.size(); i++){
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};