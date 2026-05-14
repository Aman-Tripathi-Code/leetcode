// Last updated: 5/14/2026, 8:39:46 PM
1class Solution {
2public:
3    int findCenter(vector<vector<int>>& edges) {
4        unordered_map<int,int> mp;
5        int maxi = 0;
6        for(auto &it: edges){
7            mp[it[0]]++;
8            mp[it[1]]++;
9            maxi = max({maxi,it[0],it[1]});
10        }
11
12        for(auto &it: mp){
13            if(it.second == maxi-1){
14                return it.first;
15            }
16        }
17        return -1;
18    }
19};