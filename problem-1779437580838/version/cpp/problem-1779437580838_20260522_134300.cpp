// Last updated: 5/22/2026, 1:43:00 PM
1class Solution {
2public:
3    vector<int> decode(vector<int>& nums, int first) {
4        int n = nums.size();
5        vector<int> ans;
6        ans.push_back(first);
7        for(int i = 0; i<n; i++){
8            ans.push_back(first ^ nums[i]);
9            first = first ^ nums[i];
10        }
11        return ans;
12    }
13};