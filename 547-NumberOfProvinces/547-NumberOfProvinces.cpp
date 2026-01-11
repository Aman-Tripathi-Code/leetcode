// Last updated: 1/11/2026, 1:01:33 PM
/*In this question we have to find the numbers of group of nodes which are interconnected with each other i.e. the number of components of the graph.
We can apply simply graph traversal technique and for every time the graph discontinue we can increase the count of the group of nodes*/
class Solution {
void dfs(int node, vector<int>&vis,vector<vector<int>> &isConnected){
    vis[node] = 1;
    for(int i = 0; i<vis.size(); i++){
        if(isConnected[node][i]==1&&vis[i]==-1){
            dfs(i,vis,isConnected);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt =0;
        vector<int> vis(n,-1);
        for(int i = 0; i<n; i++){
            if(vis[i]==-1){
                dfs(i,vis,isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};