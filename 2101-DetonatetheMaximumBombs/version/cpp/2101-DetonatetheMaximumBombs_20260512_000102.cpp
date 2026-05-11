// Last updated: 5/12/2026, 12:01:02 AM
1class Solution {
2public:
3    int dfs(int node, vector<bool>& vis, vector<vector<int>>& graph) {
4        vis[node] = true;
5        int cnt = 1;
6
7        for (auto& neigh : graph[node]) {
8            if (!vis[neigh]) {
9                cnt += dfs(neigh, vis, graph);
10            }
11        }
12        return cnt;
13    }
14
15    int maximumDetonation(vector<vector<int>>& bombs) {
16        int n = bombs.size(), maxi = 0;
17        vector<vector<int>> graph(n);
18
19        for (int i = 0; i < n; i++) {
20            for (int j = 0; j < n; j++) {
21                if (i == j)
22                    continue;
23                long long distBwCentre = ((bombs[i][0] - bombs[j][0]) * 1LL *
24                                          (bombs[i][0] - bombs[j][0])) +
25                                         ((bombs[i][1] - bombs[j][1]) * 1LL *
26                                          (bombs[i][1] - bombs[j][1]));
27                long long radiusSum = bombs[i][2] * 1LL * bombs[i][2];
28
29                if (distBwCentre <= radiusSum) {
30                    graph[i].push_back(j);
31                }
32            }
33        }
34
35        for (int i = 0; i < n; i++) {
36            vector<bool> vis(n, false);
37            if (!vis[i]) {
38                maxi = max(maxi, dfs(i, vis, graph));
39            }
40        }
41
42        return maxi;
43    }
44};