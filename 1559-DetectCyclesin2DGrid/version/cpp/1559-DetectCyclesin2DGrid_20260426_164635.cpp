// Last updated: 4/26/2026, 4:46:35 PM
1class Solution {
2public:
3    int dx[4] = {0, 1, 0, -1};
4    int dy[4] = {1, 0, -1, 0};
5
6    bool check(int i, int j, int n, int m) {
7        if ((i >= 0 && i < n) && (j >= 0 && j < m)) {
8            return true;
9        }
10        return false;
11    }
12
13    bool detectCycle(int row, int col, vector<vector<int>>& vis,
14                     vector<vector<char>>& grid, int pRow, int pCol, int n,
15                     int m) {
16        vis[row][col] = 1;
17        for (int i = 0; i < 4; i++) {
18            int nrow = row + dx[i], ncol = col + dy[i];
19            if (check(nrow, ncol, n, m)) {
20                if (!vis[nrow][ncol]) {
21                    if (grid[nrow][ncol] == grid[row][col]){   
22                        if (detectCycle(nrow, ncol, vis, grid, row, col,n, m)) {
23                            return true;
24                        }
25                    }
26                }else {
27                    if ((grid[nrow][ncol] == grid[row][col]) && !(nrow == pRow && ncol == pCol)) {
28                        return true;
29                    }
30                }
31            }
32        }
33        return false;
34    }
35
36    bool containsCycle(vector<vector<char>>& grid) {
37        int n = grid.size(), m = grid.front().size();
38        vector<vector<int>> vis(n, vector<int>(m, 0));
39
40        for (int i = 0; i < n; i++) {
41            for (int j = 0; j < m; j++) {
42                if (!vis[i][j]) {
43                    if (detectCycle(i, j, vis, grid, i, j, n, m)) {
44                        return true;
45                    }
46                }
47            }
48        }
49        return false;
50    }
51};