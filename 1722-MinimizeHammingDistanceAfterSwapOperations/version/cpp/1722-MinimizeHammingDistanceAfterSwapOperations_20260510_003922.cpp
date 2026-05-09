// Last updated: 5/10/2026, 12:39:22 AM
1class Solution {
2public:
3    vector<int> size, par;
4    int findPar(int node) {
5        if (node == par[node]) {
6            return node;
7        }
8        return par[node] = findPar(par[node]);
9    }
10    void unionBySize(int x, int y) {
11        int xPar = findPar(x), yPar = findPar(y);
12        if (xPar == yPar)
13            return;
14        if (size[xPar] > size[yPar]) {
15            par[yPar] = xPar;
16        } else if (size[yPar] > size[xPar]) {
17            par[xPar] = yPar;
18        } else {
19            par[yPar] = xPar;
20            size[xPar]++;
21        }
22    }
23    int minimumHammingDistance(vector<int>& source, vector<int>& target,
24                               vector<vector<int>>& allowedSwaps) {
25        int n = source.size();
26        par.resize(n, 0);
27        size.resize(n, 0);
28        for (int i = 0; i < n; i++) {
29            par[i] = i;
30            size[i] = 1;
31        }
32        int cnt = 0;
33        for (vector<int>& swap : allowedSwaps) {
34            int u = swap[0], v = swap[1];
35            if (findPar(u) != findPar(v)) {
36                unionBySize(u, v);
37            }
38        }
39
40        unordered_map<int, unordered_set<int>> mp;
41        for (int i = 0; i < n; i++) {
42            mp[target[i]].insert(i);
43        }
44
45        for (int i = 0; i < n; i++) {
46            if (mp.find(source[i]) != mp.end()) {
47                bool flag = false;
48                for (auto ind : mp[source[i]]) {
49                    if (findPar(i) == findPar(ind)) {
50                        flag = true;
51                        mp[source[i]].erase(ind);
52                        break;
53                    }
54                }
55                if(!flag) cnt++;
56            } else {
57                cnt++;
58            }
59        }
60        return cnt;
61    }
62};