// Last updated: 1/11/2026, 1:02:35 PM
class Solution {
private:
    int solve(vector<int>&nums,vector<int> &dp, int n){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick = solve(nums,dp,n-2)+nums[n];
        int notPick = solve(nums,dp,n-1);
        return dp[n]= max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        // dp[0]= nums[0];
        // for(int i = 1; i<n ; i++){
        //     int pick = nums[i];
        //     if(i>1){
        //         pick += dp[i-2];
        //     }
        //     int notPick = dp[i-1];
        //     dp[i] = max(pick,notPick);
        // }
        // return dp[n-1];
        return solve(nums,dp,n-1);
    }
};