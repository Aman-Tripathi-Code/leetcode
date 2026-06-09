// Last updated: 6/9/2026, 10:35:23 PM
1class Solution {
2    private int binPow(int a, int b, int m){
3        int res = 1;
4        while(b > 0){
5            if((b & 1) == 1){
6                res = (res * a)%m;
7            }
8            a = (a * a)%m;
9            b >>= 1;
10        }
11        return res;
12    }
13    public List<Integer> getGoodIndices(int[][] variables, int target) {
14        List<Integer> ans = new ArrayList<Integer>();
15        int n = variables.length;
16        for(int i = 0; i<n; i++){
17            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
18            int d = binPow(a,b,10);
19            int e = binPow(d,c,m);
20            if(e == target) ans.add(i);
21        }
22        return ans;
23    }
24}