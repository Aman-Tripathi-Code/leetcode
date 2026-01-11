// Last updated: 1/11/2026, 1:00:23 PM
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        //initializing the dist matrix for floyd warshal 
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j){
                    dis[i][j] = 0;
                }
            }
        }
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            dis[u][v] = weight;
            dis[v][u] = weight;
        }

        //now apply floyd warshal algorithm i.e. trying to reach each a node via every other node
        for(int via = 0; via<n; via++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dis[i][j]>dis[i][via]+dis[via][j]){
                        dis[i][j]=dis[i][via]+dis[via][j];
                    }
                }
            }
        }
        int city = -1, numberOfCities = 1e9;
        for(int i = 0 ; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(dis[i][j]!=1e9&&dis[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=numberOfCities){
                numberOfCities = cnt;
                city = i;
            }
        }
        return city;
    }
};