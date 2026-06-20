// Last updated: 6/20/2026, 9:29:22 PM
1class Solution {
2public:
3    long long dfs(int node, vector<vector<int>>&graph, vector<int>&baseTime){
4        long long latest = 0, earlier = 1e18;
5
6        for(auto &it: graph[node]){
7            long long time = dfs(it,graph,baseTime);
8            latest = max(time,latest);
9            earlier = min(time,earlier);
10        }
11        if(earlier == 1e18) return 1LL*baseTime[node];
12        long long ownTime =  (latest - earlier) + 1LL*baseTime[node];
13        return latest + ownTime;
14    }
15    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
16        vector<vector<int>> graph(n);
17        for(auto &edge: edges){
18            int u = edge[0], v = edge[1];
19            graph[u].push_back(v);
20        }
21        return dfs(0,graph,baseTime);
22    }
23};