// Last updated: 5/13/2026, 1:22:48 AM
1class Solution {
2public:
3    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
4        vector<int> deg(n,0);
5        set<pair<int,int>> st;
6        for(auto &it: roads){
7            deg[it[0]]++;
8            deg[it[1]]++;
9            st.insert({it[0],it[1]});
10        }
11        int maxi = 0;
12        for(int i = 0; i<n-1; i++){
13            for(int j = i+1; j<n; j++){
14                if(st.count({i,j}) || st.count({j,i})){
15                    maxi = max(maxi, (deg[i] + deg[j] - 1));
16                }else{
17                    maxi = max(maxi, (deg[i] + deg[j]));
18                }
19            }
20        }
21        return maxi;
22    }
23};