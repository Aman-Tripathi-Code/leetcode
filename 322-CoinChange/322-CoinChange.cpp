// Last updated: 1/11/2026, 1:02:01 PM
class Solution {
private:
    int recursion(int ind, vector<int>& coins, int amount){
        //base case
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            return 1e9;
            
        }
        //not take
        int notTake = recursion(ind-1,coins,amount);
        //take
        int take = 1e9;
        if(coins[ind]<=amount){
            take = recursion(ind,coins,amount-coins[ind]) + 1;
        }
        return min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //dp state gives the minimum number of coins that are required to make a amount j when on index i
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        for(int i = 0; i<=amount; i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                //not take
                int notTake = dp[i-1][j];
                //take
                int take = 1e9;
                if(coins[i]<=j){
                    take = dp[i][j-coins[i]] + 1;
                }
                dp[i][j] =  min(take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};