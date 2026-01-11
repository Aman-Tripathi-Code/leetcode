// Last updated: 1/11/2026, 1:02:38 PM
class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(cap+1,0)));
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<2; j++){
                for(int k = 1; k<=cap; k++){
                    if(j==0){
                        dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                    else{
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                }
            }
        }
        return dp[0][1][cap];
    }
};