// Last updated: 1/11/2026, 1:00:47 PM
class Solution {
private:
    void bfs(int i, int j,  vector<vector<int>> &vis,vector<vector<int>> &grid, int row ,int col,int &miniTime){
        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},0});
        
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int miniTime = 0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(!vis[i][j] && grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int time = it.second;
            miniTime = max(miniTime,time);
            for(int x = 0; x<4 ; x++){
                int nrow = r + di[x];
                int ncol = c + dj[x];
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col){
                    if(!vis[nrow][ncol] && grid[nrow][ncol]==1){
                        vis[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({{nrow,ncol},time+1});
                    }
                }
            }
        }


        for(auto it:grid){
            for(auto k:it){
                if(k==1){
                    return -1;
                }
            }
        }
        return miniTime;
    }
};