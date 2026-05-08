// Last updated: 5/9/2026, 3:40:34 AM
1const int N = 1e6 + 1;
2bool notPrime[N];
3bool sieveDone = false;          // ✅ run sieve only once
4
5class Solution {
6public:
7    void sieve() {
8        if (sieveDone) return;   // ✅ skip if already done
9        notPrime[0] = notPrime[1] = true;
10        for (int i = 2; i * i < N; i++) {
11            if (!notPrime[i])
12                for (int j = i * i; j < N; j += i)
13                    notPrime[j] = true;
14        }
15        sieveDone = true;
16    }
17
18    void bfs(int node, int n, vector<int>& dis, vector<vector<int>>& graph) {
19        dis[node] = 0;
20        deque<int> dq;
21        dq.push_back(node);
22
23        while (!dq.empty()) {
24            int curr = dq.front();
25            dq.pop_front();
26
27            for (auto& it : graph[curr]) {
28                int w = (curr < n && it >= n) ? 0 : 1;
29                if (dis[it] > dis[curr] + w) {
30                    dis[it] = dis[curr] + w;
31                    if (w == 0) dq.push_front(it);
32                    else dq.push_back(it);
33                }
34            }
35        }
36    }
37
38    int minJumps(vector<int>& nums) {
39        int n = nums.size();
40        sieve();
41
42        // ✅ Map each prime factor to a compact virtual node index
43        unordered_map<int, int> primeToVNode;
44        int nodeCount = n;
45
46        auto getVNode = [&](int p) {
47            if (!primeToVNode.count(p))
48                primeToVNode[p] = nodeCount++;  // assign new virtual node only when needed
49            return primeToVNode[p];
50        };
51
52        // ✅ First pass: count virtual nodes needed
53        for (int i = 0; i < n; i++) {
54            int val = nums[i];
55            for (int p = 2; (long long)p * p <= val; p++) {
56                if (val % p == 0) {
57                    getVNode(p);
58                    while (val % p == 0) val /= p;
59                }
60            }
61            if (val > 1) getVNode(val);
62        }
63
64        // ✅ graph sized to actual nodes used, not n+N
65        vector<vector<int>> graph(nodeCount);
66        vector<int> dis(nodeCount, INT_MAX);
67
68        for (int i = 0; i < n; i++) {
69            if (i + 1 < n) {
70                graph[i].push_back(i + 1);
71                graph[i + 1].push_back(i);
72            }
73
74            int val = nums[i];
75            for (int p = 2; (long long)p * p <= val; p++) {
76                if (val % p == 0) {
77                    int vNode = getVNode(p);
78                    graph[vNode].push_back(i);
79                    while (val % p == 0) val /= p;
80                }
81            }
82            if (val > 1) {
83                int vNode = getVNode(val);
84                graph[vNode].push_back(i);
85            }
86
87            if (!notPrime[nums[i]]) {
88                int vNode = getVNode(nums[i]);
89                graph[i].push_back(vNode);
90            }
91        }
92
93        bfs(0, n, dis, graph);
94        return dis[n - 1];
95    }
96};