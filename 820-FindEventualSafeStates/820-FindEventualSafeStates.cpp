// Last updated: 1/11/2026, 1:01:05 PM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> trans(n);
        vector<int> indegree(n,0);
        for(int i = 0; i<graph.size(); i++){
            for(int j = 0; j<graph[i].size(); j++){
                int u = graph[i][j];
                int v = i;
                trans[u].push_back(v);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:trans[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};