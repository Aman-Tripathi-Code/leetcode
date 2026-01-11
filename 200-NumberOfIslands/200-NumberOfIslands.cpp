// Last updated: 1/11/2026, 1:02:33 PM
class Solution {
 private:
        bool check(int i, int j, int n, int m){
            if(i<n && j<m && i>=0 && j>=0){
                return true;
            }
            return false;
        }
        void dfs(int r, int c,vector<vector<int>> &vis, vector<vector<char>> &grid,int di[],int dj[],int n,
                int m){
            vis[r][c] = 1;
            for(int i = 0; i<4; i++){
                int nr = r + di[i];
                int nc = c + dj[i];

                if(check(nr,nc,n,m)){
                    if(grid[nr][nc] == '1' && !vis[nr][nc]){
                        dfs(nr,nc,vis,grid,di,dj,n,m);
                    }
                }
            }
        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        int cnt = 0;
        for(int i= 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,vis,grid,di,dj,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};