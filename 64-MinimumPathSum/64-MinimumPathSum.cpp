// Last updated: 1/11/2026, 1:03:41 PM
class Solution {
private:
    int minimum(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)
        {
            return 1e9;
        }
        if(i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(minimum(i-1,j,grid,dp),minimum(i,j-1,grid,dp));

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minimum(n-1,m-1,grid,dp);
    }
};