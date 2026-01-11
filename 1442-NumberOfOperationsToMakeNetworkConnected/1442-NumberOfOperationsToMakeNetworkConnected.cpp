// Last updated: 1/11/2026, 1:00:24 PM
class Solution {
private:
    int findPar(int x, int par[]){
        if(x==par[x]){
            return x;
        }
        return par[x] = findPar(par[x],par);
    }
    void makeUnion(int x, int y, int par[], int rank[]){
        int xPar = findPar(x,par);
        int yPar = findPar(y,par);
        if(rank[x]>rank[y]){
            par[yPar] = xPar;
        }
        else if(rank[y]>rank[x]){
            par[xPar] = yPar;
        }
        else{
            par[yPar] = xPar;
            rank[xPar]++;
        }
    }
    void dfs(int node, vector<int>&vis,vector<vector<int>> &adj){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int par[n],rank[n];
        for(int i = 0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
        }
        vector<vector<int>> adj(n);
        int unnecessaryEdges = 0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(findPar(u,par)!=findPar(v,par)){
                makeUnion(u,v,par,rank);
            }
            else{
                unnecessaryEdges++;
            }
        }
        int cntOfComponents = 0;
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cntOfComponents++;
                dfs(i,vis,adj);
            }
        }
        // cout << unnecessaryEdges<< " " << cntOfComponents << endl;
        if(cntOfComponents-1>unnecessaryEdges){
            return -1;
        }
        return cntOfComponents-1;
    }


};