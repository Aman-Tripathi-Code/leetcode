// Last updated: 1/11/2026, 1:00:57 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i = 0; i<n; i++){
            dp[n-1][i] = mat[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j = 0; j<n; j++){
                
                int leftDia = 1e9, down = 1e9, rightDia = 1e9;
                if(j>0){
                    leftDia = dp[i+1][j-1];
                }
                if(j<n-1){
                    rightDia = dp[i+1][j+1];
                }
                down = dp[i+1][j];
                
                dp[i][j] = mat[i][j] + min(leftDia,min(down,rightDia));
            }
        }
        int ans = 1e9;
        for(int i = 0; i<n;i++){
            ans = min(ans,dp[0][i]);
        }
        return ans;
    }
};