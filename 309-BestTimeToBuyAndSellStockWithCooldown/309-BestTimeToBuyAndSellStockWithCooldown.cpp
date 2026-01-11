// Last updated: 1/11/2026, 1:02:02 PM
int dp[5001][2][2];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i = 0;i<=n;i++){
            for(int j =0;j<2; j++){
                for(int k = 0; k<2; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    if(j){
                        if(k==0){
                            dp[i][j][k] = dp[i+1][1][1];
                        }
                        else{
                            dp[i][j][k] =max(-prices[i] + dp[i+1][0][1] ,dp[i+1][1][1]);
                        }
                    }
                    else{
                        dp[i][j][k] = max(prices[i]+dp[i+1][1][0],dp[i+1][0][1]);
                    }
                }
            }
        }
        return dp[0][1][1];
    }
};