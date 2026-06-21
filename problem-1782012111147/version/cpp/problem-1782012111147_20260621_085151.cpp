// Last updated: 6/21/2026, 8:51:51 AM
1using state = pair<int,int>;
2class Solution {
3public:
4    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
5        vector<vector<state>> graph(n);
6        for(auto &it: edges){
7            int u = it[0], v = it[1], w = it[2];
8            graph[u].push_back(make_pair(v,w));
9        }
10
11        vector<vector<int>> vis(n,vector<int>(k+2,0));
12        vector<long long> dis(n,LLONG_MAX);
13
14        priority_queue<pair<int,state>> pq;
15        pq.push(make_pair(0LL,make_pair(0,1)));
16        dis[0] = 0;
17
18        while(!pq.empty()){
19            auto [dist, x] = pq.top();
20            auto [node, freq] = x;
21            pq.pop();
22            char nLbl = labels[node];
23            dist = -1*dist;
24
25            if(vis[node][freq] == 1){
26                continue;
27            }
28            vis[node][freq] = 1;
29
30            for(auto &it: graph[node]){
31                int v = it.first, w = it.second;
32                char cLbl = labels[v];
33                if(nLbl == cLbl){
34                    if(freq + 1 > k) continue;
35                    if(dis[v] > (dis[node] + w)){
36                        dis[v] = dis[node] + w;
37                        pq.push(make_pair(-dis[v],make_pair(v,freq+1)));
38                    }
39                }else{
40                    if(dis[v] > (dis[node] + w)){
41                        dis[v] = dis[node] + w;
42                        pq.push(make_pair(-dis[v],make_pair(v,1)));
43                    }
44                }
45            }
46        }
47        return (dis[n-1] == LLONG_MAX) ? -1 : dis[n-1];
48    }
49};