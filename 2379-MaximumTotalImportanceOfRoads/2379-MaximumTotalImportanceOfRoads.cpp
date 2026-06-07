// Last updated: 6/8/2026, 2:08:15 AM
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> deg(n,0);
        for(auto &road : roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }
        sort(deg.begin(),deg.end());
        for(int i = 0; i<n; i++){
            ans += (i + 1) * 1LL * deg[i];
        }
        return ans;
    }
};