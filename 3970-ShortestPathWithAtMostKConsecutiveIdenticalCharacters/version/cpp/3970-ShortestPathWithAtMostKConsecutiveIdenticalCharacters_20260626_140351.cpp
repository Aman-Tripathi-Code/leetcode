// Last updated: 6/26/2026, 2:03:51 PM
1using state = pair<long, long>;
2class Solution {
3public:
4    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
5        vector<vector<state>> graph(n);
6        for (auto& it : edges) {
7            int u = it[0], v = it[1], w = it[2];
8            graph[u].push_back(make_pair(v, w));
9        }
10
11        vector<vector<int>> vis(n, vector<int>(k + 2, 0));
12        vector<vector<long long>> dis(n, vector<long long>(k + 2, LLONG_MAX));
13
14        priority_queue<pair<int, state>> pq;
15        pq.push(make_pair(0LL, make_pair(0, 1)));
16        dis[0][1] = 0;
17
18        while (!pq.empty()) {
19            auto [dist, x] = pq.top();
20            auto [node, freq] = x;
21            pq.pop();
22            char nLbl = labels[node];
23            dist = -1 * dist;
24
25            if (vis[node][freq] == 1) {
26                continue;
27            }
28            vis[node][freq] = 1;
29
30            for (auto& it : graph[node]) {
31                int v = it.first, w = it.second;
32                char cLbl = labels[v];
33                if (nLbl == cLbl) {
34                    if (freq + 1 > k)
35                        continue;
36                    if (dis[v][freq + 1] > (dis[node][freq] + w)) {
37                        dis[v][freq + 1] = dis[node][freq] + w;
38                        pq.push(make_pair(-dis[v][freq + 1],
39                                          make_pair(v, freq + 1)));
40                    }
41                } else {
42                    if (dis[v][1] > (dis[node][freq] + w)) {
43                        dis[v][1] = dis[node][freq] + w;
44                        pq.push(make_pair(-dis[v][1], make_pair(v, 1)));
45                    }
46                }
47            }
48        }
49        long long ans = LLONG_MAX;
50
51        for (int f = 1; f <= k; f++)
52            ans = min(ans, dis[n - 1][f]);
53
54        return ans == LLONG_MAX ? -1 : ans;
55    }
56};