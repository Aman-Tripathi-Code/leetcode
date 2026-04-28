// Last updated: 4/28/2026, 11:29:10 PM
1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int n = nums.size(), ans = 1e9;
5        for(int i = 0; i<n; i++){
6            if(nums[i] == target){
7                ans = min(ans,abs(i - start));
8            }
9        }
10        return ans;
11    }
12};