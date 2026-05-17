// Last updated: 5/17/2026, 3:00:27 PM
1class Solution {
2public:
3    bool isValid(int ind, int n) { return ind >= 0 && ind < n; }
4    bool dfs(int ind, vector<int>& vis, vector<int>& arr,int n) {
5        vis[ind] = 1;
6        if (arr[ind] == 0) {
7            return true;
8        }
9        bool fwd = false, bwd = false;
10        if(isValid(ind + arr[ind], n) && !vis[ind+arr[ind]]){
11            fwd = dfs(ind+arr[ind],vis,arr,n);
12        }
13        if(isValid(ind - arr[ind], n) && !vis[ind-arr[ind]]){
14            bwd = dfs(ind-arr[ind],vis,arr,n);
15        }
16        return fwd | bwd;
17    }
18    bool canReach(vector<int>& arr, int start) {
19        int n = arr.size();
20        vector<int> vis(n, 0);
21        return dfs(start, vis, arr,n);
22    }
23};