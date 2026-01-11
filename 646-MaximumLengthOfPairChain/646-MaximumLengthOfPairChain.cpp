// Last updated: 1/11/2026, 1:01:25 PM
class Solution {
    private:
    int recursion(int ind, int prev, vector<vector<int>>& pairs,int n,vector<vector<int>> &dp){
        if(ind == n){
            return 0;
        }
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        int notTake = recursion(ind+1,prev,pairs,n,dp);
        int take = 0;
        if(prev == -1 || (pairs[ind][0] > pairs[prev][1])){
            take = 1 + recursion(ind+1,ind,pairs,n,dp);
        }
        return dp[ind][prev+1] = max(take,notTake);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recursion(0,-1,pairs,n,dp);
    }
};