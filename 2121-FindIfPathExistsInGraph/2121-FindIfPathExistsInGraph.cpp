// Last updated: 6/8/2026, 2:08:31 AM
class Solution {
public:
    void dfs(int node, int dest, vector<bool>& vis, vector<vector<int>>& graph){
        vis[node] = true;
        if(node == dest){
            return;
        }
        for(auto &it: graph[node]){
            if(!vis[it]){
                dfs(it,dest,vis,graph);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);

        for(auto &it: edges){
            int u = it[0], v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n,false);
        dfs(source,destination,vis,graph);
        return vis[destination];
    }
};