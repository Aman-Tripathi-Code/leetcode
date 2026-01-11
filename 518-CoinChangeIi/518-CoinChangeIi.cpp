// Last updated: 1/11/2026, 1:01:37 PM
class Solution {
private:
    int recursion(int ind, int amount, vector<int>&coins){
        if(ind==0){
            if(amount%coins[0]==0){
                return 1;
            }
            return 0;
        }

        //not take 
        int notTake = recursion(ind-1,amount,coins);
        //take
        int take = 0;
        if(coins[ind]<=amount){
            take = recursion(ind,amount-coins[ind],coins);
        }
        return take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i = 0; i<=amount; i++){
            if(i%coins[0]==0){
                dp[0][i] = 1;
            }
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                //not take
                int notTake = dp[i-1][j];
                //take
                int take = 0;
                if(coins[i]<=j){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};