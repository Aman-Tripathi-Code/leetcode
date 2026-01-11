// Last updated: 1/11/2026, 12:59:54 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dis(n,LONG_MAX);
        vector<long long> ways(n,0);
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){

            int u = pq.top().second;
            long long w = pq.top().first;
            pq.pop();
            if(w>dis[u]){
                continue;
            }
            for(auto it:adj[u]){
                int v = it.first;
                long long weight = it.second;
                if(dis[u]+weight<dis[v]){
                    dis[v] = dis[u]+ weight;
                    ways[v] = ways[u];
                    pq.push({dis[v],v});
                }
                else if(dis[u]+weight==dis[v]){
                    ways[v] = (ways[v]+ways[u])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};