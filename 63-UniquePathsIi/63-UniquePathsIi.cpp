// Last updated: 1/11/2026, 1:03:42 PM
class Solution {
/*we have to count the number of possible path to reach the end of matrix while been on first cell
we can have two indices i and j which represent the row and col of the curr cell 
we can explore the possibilities by going to up or left and if we reach the last cell we return 1
i.e. the path is valid and if the row or col goes out of bound we just return 0 stating that it is invalid*/
private:
    int count(int i, int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
        if(i==0&&j==0&&grid[i][j]!=1){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        if(grid[i][j]==1&&i>=0&&j>=0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = count(i-1,j,grid,dp);
        int left = count(i,j-1,grid,dp);
        return dp[i][j] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return count(m-1,n-1,obstacleGrid,dp);
    }
};