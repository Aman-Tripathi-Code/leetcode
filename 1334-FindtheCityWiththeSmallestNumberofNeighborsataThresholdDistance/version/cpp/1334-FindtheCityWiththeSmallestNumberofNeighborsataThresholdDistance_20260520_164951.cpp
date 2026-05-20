// Last updated: 5/20/2026, 4:49:51 PM
1const int INF = 1e9;
2class Solution {
3public:
4    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
5        vector<vector<int>> dis(n, vector<int>(n,INF));
6
7        for(int i = 0; i<n; i++){
8            dis[i][i] = 0;
9        }
10
11        for(auto &it : edges){
12            int u = it[0], v = it[1], w = it[2];
13            dis[u][v] = w;
14            dis[v][u] = w;
15        }
16
17        for(int k = 0; k<n; k++){
18            for(int i = 0; i < n; i++){
19                for(int j = 0; j<n; j++){
20                    dis[i][j] = min(dis[i][j], (dis[i][k] + dis[k][j]));
21                }
22            }
23        }
24        int ans = 0, mini = INF;
25        for(int i = 0; i<n; i++){
26            int city = 0;
27            for(int j = 0; j<n; j++){
28                if(dis[i][j] <= distanceThreshold && i != j){
29                    city++;
30                }
31            }  
32            if(city <= mini){
33                mini = city;
34                ans = i;
35            } 
36        }
37
38        return ans;
39        
40    }
41};