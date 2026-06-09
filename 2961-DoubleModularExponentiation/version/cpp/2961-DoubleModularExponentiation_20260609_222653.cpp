// Last updated: 6/9/2026, 10:26:53 PM
1class Solution {
2public:
3    int binPow(int a, int b, int m){
4        int res = 1;
5        while(b){
6            if(b & 1){
7                res = (res * a)%m;
8            }
9            a = (a * a)%m;
10            b >>= 1;
11        }
12        return res;
13    }
14    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
15        vector<int> ans;
16        int ind = 0;
17        for(auto &it: variables){
18            int a = it[0], b = it[1], c = it[2], m = it[3];
19            int d = binPow(a,b,10);
20            int e = binPow(d,c,m);
21            if(e == target) ans.push_back(ind);
22            ind++;
23        }
24        return ans;
25    }
26};