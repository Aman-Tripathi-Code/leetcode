// Last updated: 5/3/2026, 12:00:59 PM
1vector<vector<int>> vis;
2class Solution {
3public:
4    int dx[4] = {-1, 0, 1, 0};
5    int dy[4] = {0, 1, 0, -1};
6
7    bool isValid(int i, int j, int n, int m) {
8        return (i >= 0 && i < n && j >= 0 && j < m);
9    }
10
11    void dfs(int row, int col, vector<vector<int>>& grid, int n, int m) {
12        vis[row][col] = 1;
13
14        for (int i = 0; i < 4; i++) {
15            int nr = row + dx[i], nc = col + dy[i];
16            if (isValid(nr, nc, n, m)) {
17                if (!vis[nr][nc] && grid[nr][nc] == 1) {
18                    dfs(nr, nc, grid, n, m);
19                }
20            }
21        }
22    }
23    int numEnclaves(vector<vector<int>>& grid) {
24        int n = grid.size(), m = grid.front().size();
25        vis.assign(n, vector<int>(m, 0));
26
27        for (int i = 0; i < m; i++) {
28            if (!vis[0][i] && grid[0][i] == 1) {
29                dfs(0, i, grid, n, m);
30            }
31            if (!vis[n - 1][i] && grid[n - 1][i] == 1) {
32                dfs(n - 1, i, grid, n, m);
33            }
34        }
35
36        for (int i = 0; i < n; i++) {
37            if (!vis[i][0] && grid[i][0] == 1) {
38                dfs(i, 0, grid, n, m);
39            }
40            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
41                dfs(i, m - 1, grid, n, m);
42            }
43        }
44        int cnt = 0;
45
46        for(int i = 0; i<n; i++){
47            for(int j  = 0; j<m; j++){
48                cout << vis[i][j] << ' ';
49            }
50            cout << endl;
51        }
52
53        for (int i = 0; i < n; i++) {
54            for (int j = 0; j < m; j++) {
55                if (vis[i][j] == 0 && grid[i][j] == 1) {
56                    cnt++;
57                }
58            }
59        }
60
61        return cnt;
62    }
63};