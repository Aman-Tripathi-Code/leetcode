// Last updated: 4/23/2026, 10:49:36 PM
1class Solution {
2public:
3    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6        int pre = 0, suf = accumulate(nums.begin(),nums.end(), 0);
7        for(int i = 0; i<n; i++){
8            suf -= nums[i];
9            int res = (i * nums[i] - pre) + (suf - (n-1-i)*nums[i]);
10            pre += nums[i];
11            ans.push_back(res);
12        }
13        return ans;
14    }
15};