// Last updated: 5/3/2026, 10:49:37 AM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        int n = s.size(),  m = goal.size();
5        if(n != m) return false;
6        int i = 0, j = 0;
7
8        for(int i = 0; i<n; i++){
9            bool match = true;
10            for(int j = 0; j<m; j++){
11                if(goal[j] != s[(i+j)%n]){
12                    match = false;
13                    break;
14                }
15            }
16            if(match) return true;
17        }
18
19        return false;
20    }
21};