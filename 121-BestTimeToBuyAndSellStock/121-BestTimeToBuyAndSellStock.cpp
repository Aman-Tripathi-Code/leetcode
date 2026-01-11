// Last updated: 1/11/2026, 1:03:07 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9, profit = 0;
        for(int i = 0; i<prices.size(); i++){
            if(prices[i] < mini){
                mini = prices[i];
            }
            profit = max(profit,prices[i]-mini);
        }
        return profit;
    }
};