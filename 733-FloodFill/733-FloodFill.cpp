// Last updated: 1/11/2026, 1:01:18 PM
class Solution {
public:
    void dfs(vector<vector<int>> &ans,int initialColor, int i , int j , int color, vector<vector<int>>&vis,int row, int col){
        vis[i][j] = 1;
        ans[i][j] = color;
        if(i-1>=0&&ans[i-1][j]==initialColor&&vis[i-1][j]==0){
            dfs(ans,initialColor,i-1,j,color,vis,row,col);
        }
        if(j-1>=0&&ans[i][j-1]==initialColor&&vis[i][j-1]==0){
            dfs(ans,initialColor,i,j-1,color,vis,row,col);
        }
        if(j+1<col&&ans[i][j+1]==initialColor&&vis[i][j+1]==0){
            dfs(ans,initialColor,i,j+1,color,vis,row,col);
        }
        if(i+1<row&&ans[i+1][j]==initialColor&&vis[i+1][j]==0){
            dfs(ans,initialColor,i+1,j,color,vis,row,col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int row = image.size(), col = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> vis(row,vector<int>(col,0));
        dfs(ans,initialColor,sr,sc,color,vis,row,col);
        return ans;
    }
};