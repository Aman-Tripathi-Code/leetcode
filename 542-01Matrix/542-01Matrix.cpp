// Last updated: 1/11/2026, 1:01:35 PM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> timeMat(row,vector<int>(col));
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
               if(mat[i][j]==0){
                    q.push({0,{i,j}});
               }
            }
        }
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            vis[r][c] = 1;
            timeMat[r][c] = time;

            for(int i = 0; i<4; i++){
                int nrow = r + di[i];
                int ncol = c + dj[i];
                if(nrow>=0&&nrow<row&&ncol>=0&&ncol<col){
                    if(!vis[nrow][ncol]&&mat[nrow][ncol]==1){
                        q.push({time+1,{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return timeMat;
    }
};