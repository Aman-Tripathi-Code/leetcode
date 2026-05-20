// Last updated: 5/20/2026, 6:18:20 PM
1using state = pair<long long int,long long int>;
2
3const int mod = 1e9+7;
4class Solution {
5public:
6    int countPaths(int n, vector<vector<int>>& roads) {
7        vector<vector<state>> graph(n);
8        for(auto &it: roads){
9            int u = it[0], v = it[1], w = it[2];
10            graph[u].push_back({v,w});
11            graph[v].push_back({u,w});
12        }
13
14        vector<long long int> dis(n,1e12);
15        vector<int> vis(n,0);
16        vector<long long int> path(n,0);
17
18        priority_queue<state> q;
19        q.push({0,0});
20
21        dis[0] = 0;
22        path[0] = 1;
23
24        while(!q.empty()){
25            auto [dist,node] = q.top();
26            q.pop();
27
28            if(vis[node]) continue;
29            vis[node] = 1;
30            
31            for(auto &it: graph[node]){
32                int v = it.first, w = it.second;
33                if(dis[v] > dis[node] + w){
34                    dis[v] = dis[node] + w;
35                    path[v] = path[node];
36                    q.push({-dis[v],v});
37                }else if(dis[v] == dis[node] + w){
38                    path[v] = (path[v] + path[node])%mod;
39                }
40            }
41        }
42
43        return path[n-1] % mod;
44    }
45};