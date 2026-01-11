// Last updated: 1/11/2026, 1:00:42 PM
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, int n, int m, int di[], int dj[]){
        vis[row][col] =1;
        for(int i = 0; i<4; i++){
            int r = row+di[i];
            int c = col+dj[i];
            if(r>=0&&r<n&&c>=0&&c<m){
                if(!vis[r][c]&&grid[r][c]==1){
                    dfs(r,c,grid,vis,n,m,di,dj);
                }
            }
        }

    } 
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        vector<vector<int>> vis(row,vector<int>(col,0));
        // checking for horizontal boundary
        for(int i = 0; i<col; i++){
            //first row
            if(!vis[0][i]&&grid[0][i]==1){
                dfs(0,i,grid,vis,row,col,di,dj);
            }
            //last row
            if(!vis[row-1][i]&&grid[row-1][i]==1){
                dfs(row-1,i,grid,vis,row,col,di,dj);
            }
        }
        //checking for vertical boundary
        for(int i=0; i<row ; i++){
            //first column
            if(!vis[i][0]&&grid[i][0]==1){
                dfs(i,0,grid,vis,row,col,di,dj);
            }
            //last column
            if(!vis[i][col-1]&&grid[i][col-1]==1){
                dfs(i,col-1,grid,vis,row,col,di,dj);
            }
        }
        int cnt = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col ; j++){
                cout << vis[i][j] << " ";
                if(grid[i][j]==1&&vis[i][j]==0){
                    cnt++;
                }
            }
            cout << endl;
        }
        return cnt;
    }
};