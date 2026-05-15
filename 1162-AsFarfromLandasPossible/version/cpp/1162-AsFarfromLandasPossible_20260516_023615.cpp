// Last updated: 5/16/2026, 2:36:15 AM
1using state = pair<int, int>;
2class Solution {
3public:
4    vector<vector<int>> dis;
5    const int INF = 1e9;
6
7    int dx[4] = {-1, 0, 1, 0};
8    int dy[4] = {0, 1, 0, -1};
9
10    bool isValid(int i, int j, int n) {
11        return (i >= 0 && i < n && j >= 0 && j < n);
12    }
13
14    vector<state> neighbours(int row, int col, int n,
15                             vector<vector<int>>& grid) {
16        vector<state> neigh;
17        for (int i = 0; i < 4; i++) {
18            int nrow = row + dx[i], ncol = col + dy[i];
19            if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 0) {
20                neigh.push_back(make_pair(nrow, ncol));
21            }
22        }
23        return neigh;
24    }
25
26    void bfs(vector<vector<int>>& grid, queue<state>& q, int n) {
27        while (!q.empty()) {
28            auto [row, col] = q.front();
29            q.pop();
30
31            for (state v : neighbours(row, col, n, grid)) {
32                if (dis[v.first][v.second] > dis[row][col] + 1) {
33                    dis[v.first][v.second] = dis[row][col] + 1;
34                    q.push(make_pair(v.first, v.second));
35                }
36            }
37        }
38    }
39
40    int maxDis(int n, vector<vector<int>>& grid) {
41        int ans = -1;
42        for (int i = 0; i < n; i++) {
43            for (int j = 0; j < n; j++) {
44                if (grid[i][j] == 0) {
45                    ans = max(ans, dis[i][j]);
46                }
47            }
48        }
49        return (ans == INF) ? -1 : ans;
50    }
51
52    int maxDistance(vector<vector<int>>& grid) {
53        int n = grid.size();
54        queue<state> q;
55        dis.resize(n);
56        for (int i = 0; i < n; i++) {
57            dis[i].resize(n, INF);
58            for (int j = 0; j < n; j++) {
59                if (grid[i][j] == 1) {
60                    dis[i][j] = 0;
61                    q.push(make_pair(i, j));
62                }
63            }
64        }
65        bfs(grid, q, n);
66
67        return maxDis(n, grid);
68    }
69};