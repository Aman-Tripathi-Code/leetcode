// Last updated: 1/11/2026, 1:01:14 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> vis(n+1,0);
        vector<int> dis(n+1,1e9);

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it:times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }


        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0,k});
        dis[k] = 0;

        while(!q.empty()){
            auto tmp = q.top();
            q.pop();

            int dist = tmp.first;
            int node = tmp.second;

            for(auto it:adj[node]){
                int w = it.second;
                int v = it.first;

                if(dis[v]> dist+w){
                    dis[v] = dist + w;
                    q.push({dis[v],v});
                }
            }
        }
        int mini = -1e9;
        for(int i = 1; i<=n; i++){
            if(i!=k){
                mini = max(mini,dis[i]);
            }
        }
        if(mini == 1e9){
            return -1;
        }
        return mini;
    }
};