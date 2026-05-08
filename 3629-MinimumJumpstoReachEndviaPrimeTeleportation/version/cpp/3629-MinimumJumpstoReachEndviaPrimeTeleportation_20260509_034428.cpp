// Last updated: 5/9/2026, 3:44:28 AM
1class Solution {
2public:
3    int minJumps(vector<int>& nums) {
4        int n = nums.size();
5        int mx = *max_element(nums.begin(), nums.end());
6        
7        vector<bool> prime(mx+1, true);
8        prime[0] = false;
9        prime[1] = false;
10        for (long long i=2; i<=mx; i++) {
11            if (prime[i]) {
12                for (long long j=i*i; j<=mx; j+=i) {
13                    prime[j] = false;
14                }
15            }
16        }
17
18        vector<vector<int>> pos(mx+1);
19        for (int i=0; i<n; i++) {
20            pos[nums[i]].push_back(i);
21        }
22
23        queue<pair<int, int>> q;
24        q.push({0, 0});
25        vector<int> vis(n);
26        vis[0] = 1;
27        while (!q.empty()) {
28            auto [i, t] = q.front();
29            q.pop();
30
31            if (i == n-1) return t;
32
33            if (i > 0 && !vis[i-1]) {
34                q.push({i-1, t+1});
35                vis[i-1] = 1;
36            }
37            if (i < n-1 && !vis[i+1]) {
38                q.push({i+1, t+1});
39                vis[i+1] = 1;
40            }
41
42            if (prime[nums[i]]) {
43                int p = nums[i];
44                for (int m=p; m<=mx; m+=p) {
45                    for (int j: pos[m]) {
46                        if (!vis[j]) {
47                            q.push({j, t+1});
48                            vis[j] = 1;
49                        }
50                    }
51                    pos[m].clear();
52                }
53                prime[p] = false; 
54            }
55        }
56        return n-1;
57    }
58};