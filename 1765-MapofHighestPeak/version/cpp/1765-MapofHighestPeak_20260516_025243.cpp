// Last updated: 5/16/2026, 2:52:43 AM
1using state = pair<int, int>;
2class Solution {
3public:
4    int dx[4] = {-1, 0, 1, 0};
5    int dy[4] = {0, 1, 0, -1};
6
7    vector<state> neighbours(int row, int col, int n, int m,
8                             vector<vector<int>>& isWater) {
9        vector<state> neigh;
10        for (int i = 0; i < 4; i++) {
11            int nrow = row + dx[i], ncol = col + dy[i];
12            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
13                isWater[nrow][ncol] == 0) {
14                neigh.push_back(make_pair(nrow, ncol));
15            }
16        }
17        return neigh;
18    }
19
20    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
21        int n = isWater.size(), m = isWater.front().size();
22        vector<vector<int>> height(n, vector<int>(m, 1e9));
23        queue<state> q;
24        for (int i = 0; i < n; i++) {
25            for (int j = 0; j < m; j++) {
26                if (isWater[i][j] == 1) {
27                    height[i][j] = 0;
28                    q.push(make_pair(i, j));
29                }
30            }
31        }
32
33        while (!q.empty()) {
34            auto [row, col] = q.front();
35            q.pop();
36
37            for (state v : neighbours(row, col, n, m, isWater)) {
38                if (height[v.first][v.second] > height[row][col] + 1) {
39                    height[v.first][v.second] = height[row][col] + 1;
40                    q.push(make_pair(v.first, v.second));
41                }
42            }
43        }
44
45        return height;
46
47    }
48};