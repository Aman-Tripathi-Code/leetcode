// Last updated: 1/11/2026, 1:03:05 PM
class Solution {
private:
    int recursion(int day, int buy, int cap, vector<int>&prices, int n){
        if(cap==0){
            return 0;
        }
        if(day==n){
            return 0;
        }
        if(buy){
            return max(-prices[day]+recursion(day+1,0,cap,prices,n),recursion(day+1,1,cap,prices,n));
        }
        else{
            return max(prices[day]+recursion(day+1,1,cap-1,prices,n),recursion(day+1,0,cap,prices,n));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<2; j++){
                for(int k = 1; k<3; k++){
                    if(j==1){
                        dp[i][j][k] = max(dp[i+1][0][k]-prices[i],dp[i+1][1][k]); 
                    }
                    else{
                        dp[i][j][k] = max(dp[i+1][1][k-1]+prices[i],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};