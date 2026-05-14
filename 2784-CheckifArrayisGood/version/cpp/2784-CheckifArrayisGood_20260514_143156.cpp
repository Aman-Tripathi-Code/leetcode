// Last updated: 5/14/2026, 2:31:56 PM
1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4        int n = nums.size(), maxi = 0;
5        if(n == 1) return false;
6        sort(nums.begin(),nums.end());
7        for(int i = 0; i<n-2; i++){
8            if(nums[i] != (i+1)){
9                return false;
10            }
11        }
12        return (nums[n-2] == nums[n-1]) && (nums[n-1] == n-1);
13    }
14};