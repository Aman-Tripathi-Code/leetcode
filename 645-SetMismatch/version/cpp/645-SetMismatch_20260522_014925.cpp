// Last updated: 5/22/2026, 1:49:25 AM
1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> arr = nums;
6        vector<int> ans;
7        sort(arr.begin(),arr.end());
8        for(int i = 0; i<n; i++){
9            int lb = lower_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();
10            ans.push_back(lb);
11        }
12        return ans;
13    }
14};