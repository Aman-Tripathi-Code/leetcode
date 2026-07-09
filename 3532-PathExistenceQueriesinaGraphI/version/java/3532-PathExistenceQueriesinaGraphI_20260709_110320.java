// Last updated: 7/9/2026, 11:03:20 AM
1class Solution {
2    class DisjointSet{
3        List<Integer> rank = new ArrayList<>();
4        List<Integer> par = new ArrayList<>();
5
6        public DisjointSet(int n){
7            for(int i = 0; i<n; i++){
8                rank.add(0);
9                par.add(i);
10            }
11        }
12
13        public int findPar(int node){
14            if(node == par.get(node)){
15                return node;
16            }
17            int ulp = findPar(par.get(node));
18            par.set(node,ulp);
19            return par.get(node);
20        } 
21
22        public void unionByRank(int u, int v){
23            int ulp_u = findPar(u);
24            int ulp_v = findPar(v);
25
26            if(ulp_u == ulp_v) return;
27
28            if(rank.get(ulp_u) > rank.get(ulp_v)){
29                par.set(ulp_v,ulp_u);
30            }else if(rank.get(ulp_v) > rank.get(ulp_u)){
31                par.set(ulp_u,ulp_v);
32            }else{
33                par.set(ulp_v,ulp_u);
34                int rank_u = rank.get(ulp_u);
35                rank.set(ulp_u, rank_u + 1);
36            }
37        }
38    }
39    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
40        DisjointSet ds = new DisjointSet(n);
41
42        for(int i = 1; i<n; i++){
43            int diff = nums[i] - nums[i-1];
44            if(diff <= maxDiff){
45                ds.unionByRank(i,i-1);
46            }
47        }
48        int m = queries.length;
49        boolean[] ans = new boolean[m];
50        for(int i = 0; i<m; i++){
51            int u = queries[i][0], v = queries[i][1];
52            if(ds.findPar(u) == ds.findPar(v)){
53                ans[i] = true;
54            }else{
55                ans[i] = false;
56            }
57        }
58        return ans;
59    }
60}