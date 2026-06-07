// Last updated: 6/8/2026, 2:08:25 AM
class Solution {
public:
    int dfs(int node, vector<bool>& vis, vector<vector<int>>& graph) {
        vis[node] = true;
        int cnt = 1;

        for (auto& neigh : graph[node]) {
            if (!vis[neigh]) {
                cnt += dfs(neigh, vis, graph);
            }
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), maxi = 0;
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                long long distBwCentre = ((bombs[i][0] - bombs[j][0]) * 1LL *
                                          (bombs[i][0] - bombs[j][0])) +
                                         ((bombs[i][1] - bombs[j][1]) * 1LL *
                                          (bombs[i][1] - bombs[j][1]));
                long long radiusSum = bombs[i][2] * 1LL * bombs[i][2];

                if (distBwCentre <= radiusSum) {
                    graph[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            if (!vis[i]) {
                maxi = max(maxi, dfs(i, vis, graph));
            }
        }

        return maxi;
    }
};