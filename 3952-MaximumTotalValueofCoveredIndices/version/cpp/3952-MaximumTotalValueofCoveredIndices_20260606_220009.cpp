// Last updated: 6/6/2026, 10:00:09 PM
1class Solution {
2public:
3    long long rec(int i, vector<int>& nums, string &s, vector<vector<long long>>& dp, bool flag){
4        if(i == 0){
5            if(flag || s[i] == '1'){
6                return 1LL*nums[i];
7            }else{
8                return 0LL;
9            }
10        }
11        if(dp[i][flag] != -1) return dp[i][flag];
12        long long ans = 0;
13        if(s[i] == '0'){
14            if(flag) ans = 1LL*nums[i] + rec(i-1,nums,s,dp,0);
15            else ans = rec(i-1, nums, s, dp, 0);
16        }else{
17            if(flag) ans = 1LL*nums[i] + rec(i-1, nums, s, dp, 1);
18            else{
19                long long take = 1LL*nums[i] + rec(i-1, nums, s, dp, 0);
20                long long notTake = rec(i-1, nums, s, dp , 1);
21                ans = max(take, notTake);
22            }
23        }
24        return dp[i][flag] = ans;
25    }
26    long long maxTotal(vector<int>& nums, string s) {
27        int n = nums.size();
28        vector<vector<long long>> dp(n,vector<long long>(2,-1));
29        return rec(n-1,nums,s,dp,0);
30    }
31};