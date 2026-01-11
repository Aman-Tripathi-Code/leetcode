// Last updated: 1/11/2026, 1:01:26 PM
class Solution {
public:
    int minDistance(string s, string q) {
        int n1 = s.size(),n2 = q.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i = 1; i<=n1; i++){
            for(int j = 1; j<=n2; j++){
                
                int take = -1e9;
                if(s[i-1]==q[j-1]){
                    take = 1 + dp[i-1][j-1];
                }
                
                int notTake = max(dp[i-1][j],dp[i][j-1]);

                dp[i][j] = max(take,notTake);
            }
        }
        return (n1-dp[n1][n2]+n2-dp[n1][n2]);
    }
};