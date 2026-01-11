// Last updated: 1/11/2026, 1:03:08 PM
class Solution {
// we are at the top of a triangle and we have to reach the bottom 
// we have to find the minimum path sum 
// Expressing :- we can express in term of index startrow,startcol
// Exploring :- we can explore the grid by going in only two directions
    // downwards and diagonally right
// Find min/max :- we can add the curr grid elmenent to our ans and move to the desired directions
// base condition :- we can restrict the recursion at the last row by returning its value
public:
    int miniPathSum(int i, int j, vector<vector<int>>&triangle,vector<vector<int>> &dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = triangle[i][j] + miniPathSum(i+1,j,triangle,dp);
        int downright = triangle[i][j] + miniPathSum(i+1,j+1,triangle,dp);
        return dp[i][j] = min(down,downright);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row,vector<int>(row,-1));
        return miniPathSum(0,0,triangle,dp);
    }
};