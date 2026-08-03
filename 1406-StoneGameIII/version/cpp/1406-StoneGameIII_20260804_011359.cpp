// Last updated: 8/4/2026, 1:13:59 AM
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        int n = stoneValue.size();
5        vector<int> suffixSum(n+1, 0);
6        vector<int> dp(n+1, 0);
7        for (int i = n - 1; i >= 0; i--)
8            suffixSum[i] = suffixSum[i + 1] + stoneValue[i];
9        for (int i = n-1; i >= 0; i--) {
10            dp[i] = stoneValue[i] + suffixSum[i+1] - dp[i+1];
11            for (int k = i+1; k < i+3 && k < n; k++) {
12                dp[i] = max(dp[i],  suffixSum[i]-dp[k+1]);
13            }
14        }
15        if (dp[0]*2 == suffixSum[0])
16            return "Tie";
17        else if (dp[0]*2 > suffixSum[0])
18            return "Alice";
19        else
20            return "Bob";
21    }
22};