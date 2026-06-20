// Last updated: 6/20/2026, 10:11:16 PM
1class Solution {
2public:
3    vector<string> createGrid(int n, int m) {
4        vector<string> ans(n);
5        for(int i = 0; i<n; i++){
6            if(i == 0){
7                string s(m,'.');
8                ans[i] = s; 
9            }
10            else{
11                string s(m,'#');
12                s[m-1] = '.';
13                ans[i] = s; 
14            }
15        }
16        return ans;
17    }
18};