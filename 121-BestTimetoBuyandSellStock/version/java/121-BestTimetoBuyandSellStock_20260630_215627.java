// Last updated: 6/30/2026, 9:56:27 PM
1class Solution {
2    public int maxProfit(int[] prices) {
3        int n = prices.length, maxi = 0, buyPrice = prices[0];
4        for(int i = 1; i<n; i++){
5            if(prices[i] < buyPrice){
6                buyPrice = prices[i];
7            }
8            maxi = Math.max(maxi,(prices[i]-buyPrice));
9        }
10        return maxi;
11    }
12}