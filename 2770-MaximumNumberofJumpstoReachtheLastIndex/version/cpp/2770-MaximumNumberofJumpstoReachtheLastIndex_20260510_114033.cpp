// Last updated: 5/10/2026, 11:40:33 AM
1class Solution {
2public:
3    int memoization(int ind, vector<int>&dp, vector<int>& nums, int target, int n){
4        if(ind == n-1){
5            return 0;
6        }
7        int ans = -1e9;
8        if(dp[ind] != -1) return dp[ind];
9        for(int j = ind+1; j<n; j++){
10            if(abs(nums[j]-nums[ind]) <= target){
11                ans = max(ans,1 + memoization(j,dp,nums,target,n));
12            }
13        }
14        return dp[ind] = ans;
15    }
16    int maximumJumps(vector<int>& nums, int target) {
17        int n  = nums.size();
18        vector<int> dp(n,-1);
19        int ans = memoization(0,dp,nums,target,n);
20        return (ans < 0) ? -1 : ans;
21    }
22};