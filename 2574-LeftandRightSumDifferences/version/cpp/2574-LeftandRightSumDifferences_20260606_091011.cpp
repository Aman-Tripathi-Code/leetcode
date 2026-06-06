// Last updated: 6/6/2026, 9:10:11 AM
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        int leftSum = 0, rightSum = accumulate(nums.begin(),nums.end(),0);
7        for(int i = 0; i<n; i++){
8            rightSum -= nums[i];
9            ans[i] = abs(leftSum-rightSum);
10            leftSum += nums[i];
11        }
12        return ans;
13    }
14};