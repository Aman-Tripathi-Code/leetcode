// Last updated: 1/11/2026, 1:02:30 PM
class Solution {
private:
    bool isCycle(int node, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &adj){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(isCycle(it,vis,dfsVis,adj)){
                    return true;
                }
            }
            else if(dfsVis[it] == 1){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses);
        vector<int> dfsVis(numCourses);

        vector<vector<int>> adj(numCourses);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i<numCourses; i++){
            if(vis[i] == 0){
                if(isCycle(i,vis,dfsVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};