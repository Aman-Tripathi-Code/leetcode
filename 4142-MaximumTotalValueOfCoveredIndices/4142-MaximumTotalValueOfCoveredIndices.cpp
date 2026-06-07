// Last updated: 6/8/2026, 2:07:22 AM
class Solution {
public:
    long long rec(int i, vector<int>& nums, string &s, vector<vector<long long>>& dp, bool flag){
        if(i == 0){
            if(flag || s[i] == '1'){
                return 1LL*nums[i];
            }else{
                return 0LL;
            }
        }
        if(dp[i][flag] != -1) return dp[i][flag];
        long long ans = 0;
        if(s[i] == '0'){
            if(flag) ans = 1LL*nums[i] + rec(i-1,nums,s,dp,0);
            else ans = rec(i-1, nums, s, dp, 0);
        }else{
            if(flag) ans = 1LL*nums[i] + rec(i-1, nums, s, dp, 1);
            else{
                long long take = 1LL*nums[i] + rec(i-1, nums, s, dp, 0);
                long long notTake = rec(i-1, nums, s, dp , 1);
                ans = max(take, notTake);
            }
        }
        return dp[i][flag] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return rec(n-1,nums,s,dp,0);
    }
};