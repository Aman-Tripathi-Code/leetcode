// Last updated: 1/11/2026, 1:03:06 PM
class Solution {
    int recursion(int day, int buy , vector<int>&prices, int n,vector<vector<int>> &dp){
        if(day == n){
            return 0;
        }
        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }
        if(buy){
            dp[day][buy] = max(-prices[day]+recursion(day+1,0,prices,n,dp),recursion(day+1,1,prices,n,dp));
        }
        else{
            dp[day][buy] =  max(prices[day]+recursion(day+1,1,prices,n,dp),recursion(day+1,0,prices,n,dp));
        }
        return dp[day][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recursion(0,1,prices,n,dp);
    }
};