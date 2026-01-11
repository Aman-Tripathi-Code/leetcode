// Last updated: 1/11/2026, 1:01:21 PM
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    void dfs(int node, unordered_map<int,int> &vis, unordered_map<int,vector<int>> &adj, int &totImp, unordered_map<int,int> &val){
        vis[node] = 1;
        totImp += val[node];
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,totImp,val);
            }
        }
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> val;
        unordered_map<int,int> vis;
        for(auto it:employees){
            int u = it->id;
            int imp = it->importance;
            val[u] = imp;
            vis[u] = 0;
            cout << u << " " << imp << endl;
            if(it->subordinates.size()>0){
                for(auto sub:it->subordinates){
                    adj[u].push_back(sub);
                }
            }
        }
        int totImp = 0;
        dfs(id,vis,adj,totImp,val);
        return totImp;
    }
};