// Last updated: 1/11/2026, 1:01:38 PM
class Solution {
public:
    int longestPalindromeSubseq(string q) {
        string r = q;
        reverse(r.begin(),r.end());
        string s = r;
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                
                int take = -1e9;
                if(s[i-1]==q[j-1]){
                    take = 1 + dp[i-1][j-1];
                }
                
                int notTake = max(dp[i-1][j],dp[i][j-1]);

                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n][n];
    }
};