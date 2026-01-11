// Last updated: 1/11/2026, 1:01:07 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<flights.size(); i++){
            auto it = flights[i];
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        set<pair<int,pair<int,int>>> st;
        vector<int> dist(n,1e9);

        //st->lvl,{node,dist};
        //because some time the travel is possible but it will choose the shortest path and never choose the valid path
        st.insert({0,{src,0}});
        dist[src] = 0;
        int ans = 1e9;
        while(!st.empty()){
            auto it = *(st.begin());
            int lvl = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(lvl <= k+1 && node == dst){
                ans = min(ans,dis);
            }
            st.erase({lvl,{node,dis}});

            for(auto v:adj[node]){
                int nd = v.first;
                int weight = v.second;
                if(dist[nd]>dis+weight){
                    dist[nd] = dis+weight;
                    st.insert({lvl+1,{nd,dist[nd]}});
                }
            }
        }
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};