// Last updated: 7/12/2026, 1:43:23 AM
1class Solution {
2public:
3    void dfs(int node, vector<int> &vis, vector<vector<int>>& graph, int &nodeCount, int &edgeCount){
4        vis[node] = 1;
5
6        nodeCount++;
7        edgeCount += graph[node].size();
8
9        for(auto &it: graph[node]){
10            if(!vis[it]){
11                dfs(it,vis,graph,nodeCount, edgeCount);
12            }
13        }
14        
15    }
16    int countCompleteComponents(int n, vector<vector<int>>& edges) {
17        int cnt = 0;
18        vector<vector<int>> graph(n);
19        for(auto edge: edges){
20            int u = edge[0], v = edge[1];
21            graph[u].push_back(v);
22            graph[v].push_back(u);
23        }
24
25        vector<int> vis(n,0);
26
27        for(int i = 0; i<n; i++){
28            if(!vis[i]){
29                int edgeCount = 0, nodeCount = 0;
30                dfs(i,vis,graph,nodeCount,edgeCount);
31                // cout << i << ' ' << edgeCount << ' ' << nodeCount << endl;
32                if((edgeCount) == (nodeCount * (nodeCount-1))){
33                    cnt++;
34                }
35            }
36        }
37        return cnt;
38    }
39};