// Last updated: 4/28/2026, 10:52:53 PM
1class Solution {
2public:
3    int minMoves2(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        int ans = 0, median = nums[n/2];
7        for(int i= 0; i<n; i++){
8            ans += abs(nums[i] - median);
9        }
10        return ans;
11    }
12};