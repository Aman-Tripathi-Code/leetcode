// Last updated: 5/20/2026, 7:21:34 PM
1using state = pair<int,pair<int,int>>;
2class Solution {
3public:
4    int minimumEffortPath(vector<vector<int>>& heights) {
5        int n = heights.size(), m = heights.front().size();
6
7        vector<vector<int>> dis(n,vector<int>(m,1e9));
8        vector<vector<int>> vis(n,vector<int>(m,0));
9
10        priority_queue<state> pq;
11        pq.push({0,{0,0}});
12        dis[0][0] = 0;
13
14        int dx[4] = {-1,0,1,0};
15        int dy[4] = {0,1,0,-1};
16
17        while(!pq.empty()){
18            auto [dist, coordinate] = pq.top();
19            auto [row, col] = coordinate;
20            pq.pop();
21
22            if(vis[row][col]) continue;
23            vis[row][col] = 1;
24
25            for(int i = 0; i<4; i++){
26                int nrow = row + dx[i], ncol = col + dy[i];
27
28                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m){
29                    int weight = abs(heights[row][col] - heights[nrow][ncol]);
30
31                    if(dis[nrow][ncol] > max(weight,dis[row][col])){
32                        dis[nrow][ncol] = max(weight,dis[row][col]);
33                        pq.push({-1*dis[nrow][ncol],{nrow,ncol}});
34                    }
35                }
36            }
37        }
38        return dis[n-1][m-1];
39    }
40};