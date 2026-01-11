// Last updated: 1/11/2026, 1:01:08 PM
class Solution {
public:
    bool dfs(int node, vector<vector<int>>&graph, vector<int>&color,vector<int> &vis){
        if(color[node]==-1){
            color[node]=1;
        }
        vis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                color[it] = 1-color[node];
                if(dfs(it,graph,color,vis)==false){
                    return false;
                };
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> color(V,-1);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(!dfs(i,graph,color,vis)){
                    return false;
                }
            }
        }
        return true;
        
    }
};