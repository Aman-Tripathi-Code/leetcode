// Last updated: 1/11/2026, 1:00:56 PM
class Solution {
private:
    bool check(int i, int j, int n){
        if(i<n && i>=0 && j<n && j>=0){
            return true;
        }
        return false;
    }
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int di[], int dj[],       vector<vector<int>> &dist,queue<pair<int,pair<int,int>>> &pq){
            vis[r][c] = 1;
            dist[r][c] = 0;
            pq.push({0,{r,c}});
            for(int i = 0; i<4; i++){
                int nr = r + di[i];
                int nc = c + dj[i];
                if(check(nr,nc,n)){
                    if(!vis[nr][nc] && grid[nr][nc] == 1){
                        dfs(nr,nc,vis,grid,n,di,dj,dist,pq);
                    }
                }
                
            }
        }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> pq;
        int di[4] = {-1,0,1,0};
        int dj[4] = {0,1,0,-1};
        bool flag = false;


        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    dfs(i,j,vis,grid,n,di,dj,dist,pq);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        int mini = 1e9;
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0; i<4; i++){
                int nr = r + di[i];
                int nc = c + dj[i];

                if(check(nr,nc,n)){
                    if(!vis[nr][nc]){
                        if(dist[nr][nc]>dis + 1){
                            dist[nr][nc] = dis + 1;
                            pq.push({dis+1,{nr,nc}});
                            if(grid[nr][nc]==1){
                                mini = min(mini,dis);
                            }
                        }
                    }
                }
            }
        }

        return mini;
    
    }
};