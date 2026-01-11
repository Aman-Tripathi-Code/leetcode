// Last updated: 1/11/2026, 1:03:36 PM
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i<=m; i++){
            dp[0][i] = i;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    int mini = 1 + min(insert,min(del,replace));
                    dp[i][j] = mini;
                }
            }
        }
        return dp[n][m];
    }
};