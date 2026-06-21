// Last updated: 6/21/2026, 4:07:03 PM
class Solution {
private:
    int minCycle = INT_MAX;

    void dfs(vector<int>& visited, vector<unordered_set<int>>& graph, int node, int level, int parent) {
        if (visited[node] > 0) {
            if (level - visited[node] > 0) {
                minCycle = min(minCycle, level - visited[node]);
            }
            return;
        }

        visited[node] = level;

        for (int next : graph[node]) {
            if (next == parent) continue;
            dfs(visited, graph, next, level + 1, node);
        }
    }

public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);

        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] > 0) continue;
            dfs(visited, graph, i, 1, -1);
        }

        return minCycle == INT_MAX ? -1 : minCycle;
    }
};
