// Last updated: 6/8/2026, 2:08:07 AM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int leftSum = 0, rightSum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i<n; i++){
            rightSum -= nums[i];
            ans[i] = abs(leftSum-rightSum);
            leftSum += nums[i];
        }
        return ans;
    }
};