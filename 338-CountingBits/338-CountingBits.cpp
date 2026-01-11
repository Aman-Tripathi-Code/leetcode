// Last updated: 1/11/2026, 1:02:00 PM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i = 0; i<=n; i++){
            dp[i] = __builtin_popcount(i);
        }
        return dp;
    }
};