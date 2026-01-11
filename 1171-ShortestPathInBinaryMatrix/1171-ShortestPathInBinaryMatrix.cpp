// Last updated: 1/11/2026, 1:00:35 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1){
            return -1;
        }
        set <pair<int,pair<int,int>>> st;
        st.insert({1,{0,0}});
        int ans = 1e9;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;

        int di[] = {-1,-1,0,1,1,1,0,-1};
        int dj[] = {0,1,1,1,0,-1,-1,-1};
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            st.erase({dis,{r,c}});
            if(r==n-1&&c==n-1){
                ans = min(ans,dist[r][c]);
            }

            for(int i = 0; i<8; i++){
                int nrow = r + di[i];
                int ncol = c + dj[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 ){
                    if(dist[nrow][ncol]>dist[r][c]+1){
                        if(dist[nrow][ncol]!=1e9){
                            st.erase({dist[nrow][ncol],{nrow,ncol}});
                        }
                        dist[nrow][ncol] = dist[r][c] + 1;
                        st.insert({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};