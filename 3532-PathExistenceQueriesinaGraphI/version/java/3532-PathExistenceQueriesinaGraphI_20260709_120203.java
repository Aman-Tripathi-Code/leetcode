// Last updated: 7/9/2026, 12:02:03 PM
1class Solution {
2    class DisjointSet{
3        int[] rank;
4        int[] par;
5
6        public DisjointSet(int n){
7            rank = new int[n];
8            par = new int[n];
9            for(int i = 0; i<n; i++){
10                rank[i] = 0;
11                par[i] = i;
12            }
13        }
14
15        public int findPar(int node){
16            if(node == par[node]){
17                return node;
18            }
19            return par[node] = findPar(par[node]);
20        } 
21
22        public void unionByRank(int u, int v){
23            int ulp_u = findPar(u);
24            int ulp_v = findPar(v);
25
26            if(ulp_u == ulp_v) return;
27
28            if(rank[ulp_u] > rank[ulp_v]){
29                par[ulp_v] = ulp_u;
30            }else if(rank[ulp_v] > rank[ulp_u]){
31                par[ulp_u] = ulp_v;
32            }else{
33                par[ulp_v] = ulp_u;
34                rank[ulp_u] += 1;
35            }
36        }
37    }
38    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
39        DisjointSet ds = new DisjointSet(n);
40
41        for(int i = 1; i<n; i++){
42            int diff = nums[i] - nums[i-1];
43            if(diff <= maxDiff){
44                ds.unionByRank(i,i-1);
45            }
46        }
47        int m = queries.length;
48        boolean[] ans = new boolean[m];
49        for(int i = 0; i<m; i++){
50            int u = queries[i][0], v = queries[i][1];
51            if(ds.findPar(u) == ds.findPar(v)){
52                ans[i] = true;
53            }else{
54                ans[i] = false;
55            }
56        }
57        return ans;
58    }
59}