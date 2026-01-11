// Last updated: 1/11/2026, 1:02:03 PM
class Solution {
private:
    int recursion(int ind , int prev, vector<int>& a, int n,vector<vector<int>> &dp){
            if(ind==n){
                return 0;
            }
            if(dp[ind][prev+1]!=-1){
                return dp[ind][prev+1];
            }
            int notTake = recursion(ind+1,prev,a,n,dp);
            int take = 0;
            if(prev == -1 || a[ind]>a[prev]){
                take = 1 + recursion(ind+1,ind,a,n,dp);
            }
            return dp[ind][prev+1] = max(take,notTake);   
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recursion(0,-1,nums,n,dp);
        
    }
};


// vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        // for(int i = n-1; i>=0; i--){
        //     for(int j = n-1; j>=-1; j--){
        //         int notTake = dp[i+1][j+1];
        //         int take = 0;
        //         if(j==-1 || nums[i]>nums[j]){
        //             take = 1 + dp[i+1][i+1];
        //         }
        //         dp[i][j+1] = max(take,notTake);
        //     }
        // }
        // return dp[0][0];