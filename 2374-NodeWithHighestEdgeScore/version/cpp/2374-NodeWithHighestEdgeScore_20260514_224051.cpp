// Last updated: 5/14/2026, 10:40:51 PM
1class Solution {
2public:
3    int edgeScore(vector<int>& edges) {
4        int n = edges.size(), ans = 0;
5        long long maxi = 0;
6        vector<long long> indegreeSum(n,0);
7        for(int i = 0; i<n; i++){
8            indegreeSum[edges[i]] += i;
9            if(indegreeSum[edges[i]] > maxi){
10                ans = edges[i];
11                maxi = indegreeSum[edges[i]];
12            }else if(indegreeSum[edges[i]] == maxi){
13                if(edges[i] < ans) ans = edges[i];
14            }
15        }
16        return ans;
17    }
18};