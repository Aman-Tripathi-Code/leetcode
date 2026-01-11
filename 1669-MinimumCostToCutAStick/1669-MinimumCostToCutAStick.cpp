// Last updated: 1/11/2026, 1:00:08 PM
class Solution {
private:
int recursion(int i, int j, vector<int>&cut,vector<vector<int>> &dp){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = 1e9;
    for(int k = i; k<j; k++){
        int cost = cut[j]-cut[i-1] + recursion(i,k,cut,dp) + recursion(k+1,j,cut,dp);
        dp[i][j] = min(dp[i][j],cost);
    }
    return dp[i][j];
}
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        int sz = cuts.size();
        vector<vector<int>> dp(sz,vector<int>(sz,-1));
        return recursion(1,sz-1,cuts,dp);
    }
};