// Last updated: 4/30/2026, 11:05:17 PM
1class Solution {
2public:
3    int dx[4] = {-1,0,1,0};
4    int dy[4] = {0,1,0,-1};
5
6    bool isValid(int i, int j, int n, int m){
7        if(i >= 0 && i < n && j >= 0 && j < m){
8            return true;
9        }
10        return false;
11    }
12
13    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m){
14        vis[r][c] = 1;
15        for(int i = 0; i<4; i++){
16            int nr = r + dx[i], nc = c + dy[i];
17            if(isValid(nr,nc,n,m)){
18                if(!vis[nr][nc] && grid[nr][nc] == '1'){
19                    dfs(nr,nc,vis,grid,n,m);
20                }
21            }
22        }
23    }
24    int numIslands(vector<vector<char>>& grid) {
25        int n = grid.size(), m = grid[0].size();
26        vector<vector<int>> vis(n,vector<int>(m,0));
27        int cnt  = 0;
28        for(int i = 0; i<n; i++){
29            for(int j = 0; j<m; j++){
30                if(!vis[i][j] && (grid[i][j] == '1')){
31                    dfs(i,j,vis,grid,n,m);
32                    cnt++;
33                }
34            }
35        }
36        return cnt;
37    }
38};