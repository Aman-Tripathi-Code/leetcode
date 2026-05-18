// Last updated: 5/18/2026, 9:38:14 PM
1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4        int n = arr.size();
5        unordered_map<int,vector<int>> mp;
6
7        for(int i = 0; i<n; i++){
8            mp[arr[i]].push_back(i);
9        }
10
11
12        vector<int> dis(n,1e9);
13        vector<int> vis(n,0);
14
15        queue<int> q;
16        q.push(0);
17        dis[0] = 0;
18
19        while(!q.empty()){
20            int node = q.front();
21            q.pop();
22
23            if(node == n-1) return dis[n-1];
24
25            if(vis[node]) continue;
26            vis[node] = 1;
27
28            if(node - 1 >= 0){
29                if(dis[node-1] > dis[node] + 1){
30                    dis[node-1] = dis[node] + 1;
31                    q.push(node-1);
32                }
33                
34            }
35            if(node + 1 < n){
36                if(dis[node+1] > dis[node] + 1){
37                    dis[node+1] = dis[node] + 1;
38                    q.push(node+1);
39                }
40            }
41
42            for(auto &it: mp[arr[node]]){
43                if(it == node) continue;
44                if(dis[it] > dis[node] + 1){
45                    dis[it] = dis[node] + 1;
46                    q.push(it);
47                }
48            }
49            mp.erase(arr[node]);
50            
51        }
52        return dis[n-1];
53    }
54};