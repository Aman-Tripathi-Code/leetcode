// Last updated: 5/14/2026, 2:50:05 AM
1using state = pair<pair<int,int>, int>;
2class Solution {
3public:
4    int maximumPopulation(vector<vector<int>>& logs) {
5        vector<state> pop;
6        for(auto &it: logs){
7            pop.push_back({{it[0],1}, 1});
8            pop.push_back({{it[1],0},-1});
9        }
10        sort(pop.begin(),pop.end());
11
12        int maxCnt = -1e9, cnt = 0, ans = 0;
13        for(auto&it: pop){
14            cnt += it.second;
15            if(cnt > maxCnt){
16                ans = it.first.first;
17            }
18            maxCnt = max(maxCnt,cnt);
19        }
20
21        return ans;
22    }
23};