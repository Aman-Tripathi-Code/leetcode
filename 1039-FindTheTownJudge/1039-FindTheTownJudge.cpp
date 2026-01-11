// Last updated: 1/11/2026, 1:00:46 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1);
        for(auto it:trust){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
            indegree[u]--;
        }
        int ans = -1;
        for(int i = 1; i<=n; i++){
            if(indegree[i]==n-1){
                ans = i;
            }
        }
        return ans;
    }
};