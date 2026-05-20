// Last updated: 5/20/2026, 6:46:33 PM
1using state = pair<int,int>;
2class Solution {
3public:
4    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
5        vector<vector<state>> graph(n+1);
6
7        for(auto &it: times){
8            int u = it[0], v = it[1], w = it[2];
9            graph[u].push_back({v,w});
10        }
11
12        priority_queue<state> pq;
13        pq.push({0,k});
14
15        vector<int> vis(n+1,0);
16        vector<int> dis(n+1,1e9);
17
18        dis[k] = 0;
19
20        while(!pq.empty()){
21            auto [dist,node] = pq.top();
22            pq.pop();
23
24            if(vis[node]) continue;
25            vis[node] = 1;
26
27            for(auto &it: graph[node]){
28                int v = it.first, w = it.second;
29                if(dis[v] > dis[node] + w){
30                    dis[v] = dis[node] + w;
31                    pq.push({-1*dis[v],v});
32                }
33            }
34        }
35
36        int maxi = -1;
37        for(int i = 1; i<=n; i++){
38            if(dis[i] == 1e9) return -1;
39            maxi = max(dis[i], maxi);
40        }
41
42        return maxi;
43
44    }
45};