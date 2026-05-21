// Last updated: 5/21/2026, 3:00:05 PM
1class Solution {
2public:
3    int countPairs(vector<int>& d) {
4        int n = d.size(), mod = 1e9+7;
5        long long ans = 0;
6        unordered_map<int,int> mp;
7        for(int i = 0; i<n; i++){
8            for(int j = 0; j<=21; j++){
9                int target = (1 << j) - d[i];
10                if(mp.find(target) != mp.end()){
11                    ans = (ans + mp[target])%mod;
12                }
13            }
14            mp[d[i]]++;
15        }
16        return ans % mod;
17    }
18};