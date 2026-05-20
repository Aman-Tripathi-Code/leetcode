// Last updated: 5/20/2026, 8:51:07 PM
1using state = pair<int, int>;
2class Solution {
3public:
4    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
5                          int k) {
6        vector<vector<state>> graph(n);
7        for (auto& it : flights) {
8            int u = it[0], v = it[1], w = it[2];
9            graph[u].push_back({v, w});
10        }
11        vector<vector<int>> dis(n, vector<int>(k + 2, 1e9));
12        vector<vector<int>> vis(n, vector<int>(k + 2, 0));
13        priority_queue<state, vector<state>, greater<state>> pq;
14        pq.push({0, src});
15        dis[src][0] = 0;
16        while (!pq.empty()) {
17            auto [stop, node] = pq.top();
18            pq.pop();
19
20            if (stop > k)
21                break;
22
23            if (vis[node][stop])
24                continue;
25            vis[node][stop] = 1;
26
27            for (auto& v : graph[node]) {
28                if (dis[v.first][stop + 1] > dis[node][stop] + v.second) {
29                    dis[v.first][stop + 1] = dis[node][stop] + v.second;
30                    pq.push({(stop + 1), v.first});
31                }
32            }
33        }
34        int mini = 1e9;
35        for (int j = 0; j <= k + 1; j++) {
36            mini = min(mini,dis[dst][j]);
37        }
38        return (mini == 1e9) ? -1 : mini;
39    }
40};