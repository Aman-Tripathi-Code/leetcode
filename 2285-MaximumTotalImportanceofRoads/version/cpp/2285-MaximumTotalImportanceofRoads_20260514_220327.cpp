// Last updated: 5/14/2026, 10:03:27 PM
1class Solution {
2public:
3    long long maximumImportance(int n, vector<vector<int>>& roads) {
4        long long ans = 0;
5        vector<int> deg(n,0);
6        for(auto &road : roads){
7            deg[road[0]]++;
8            deg[road[1]]++;
9        }
10        sort(deg.begin(),deg.end());
11        for(int i = 0; i<n; i++){
12            ans += (i + 1) * 1LL * deg[i];
13        }
14        return ans;
15    }
16};