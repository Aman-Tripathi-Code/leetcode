// Last updated: 4/30/2026, 2:35:17 AM
1class Solution {
2public:
3
4    bool check(int r, int c, int n, int m){
5        if((r >= 0 && r < n) && (c >= 0 && c < m)){
6            return true;
7        }
8        return false;
9    }
10
11    int orangesRotting(vector<vector<int>>& grid) {
12        int n = grid.size(), m = grid[0].size();
13        int dx[4] = {1,0,-1,0};
14        int dy[4] = {0,-1,0,1};
15        vector<vector<int>> dis(n,vector<int>(m,0));
16        vector<vector<int>> vis(n,vector<int>(m,0));
17
18        queue<pair<int,int>> q;
19        for(int i = 0; i<n; i++){
20            for(int j = 0; j<m; j++){
21                if(grid[i][j] == 2){
22                    q.push({i,j});
23                }else{
24                    dis[i][j] = 1e9;
25                }
26            }
27        }
28
29        while(!q.empty()){
30            int row = q.front().first, col = q.front().second;
31            q.pop();
32
33            if(vis[row][col]){
34                continue;
35            }
36
37            vis[row][col] = 1;
38
39            for(int i = 0; i<4; i++){
40                int nrow = row + dx[i] , ncol = col + dy[i];
41                if(check(nrow,ncol,n,m) && grid[nrow][ncol] == 1){
42                    if(dis[nrow][ncol] > (dis[row][col] + 1)){
43                        q.push({nrow,ncol});
44                        dis[nrow][ncol] = dis[row][col] + 1;
45                    }
46                }
47            }
48        }
49        int mini = 0;
50        for(int i = 0; i<n; i++){
51            for(int j = 0; j<m; j++){
52                if(grid[i][j] == 1){
53                    mini = max(dis[i][j], mini);
54                }
55            }
56        }
57        return (mini == 1e9) ? -1 : mini;
58    }
59};