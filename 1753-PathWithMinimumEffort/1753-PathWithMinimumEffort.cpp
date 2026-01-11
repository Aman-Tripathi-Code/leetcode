// Last updated: 1/11/2026, 1:00:02 PM
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});


        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};

        while(!st.empty()){
            auto it = *(st.begin());

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            st.erase({dis,{r,c}});

            for(int i = 0; i<4 ; i++){
                int nr = r + di[i];
                int nc = c + dj[i];

                if(nr>=0&&nr<n && nc>=0&&nc<m){
                    if(dist[nr][nc]>max(dist[r][c],abs(heights[r][c]-heights[nr][nc]))){
                        if(dist[nr][nc]!=1e9){
                            st.erase({dist[nr][nc],{nr,nc}});
                        }
                        dist[nr][nc] = max(dist[r][c],abs(heights[r][c]-heights[nr][nc]));
                        st.insert({dist[nr][nc],{nr,nc}});
                    }
                }
            } 
        }
        return dist[n-1][m-1];
    }
};