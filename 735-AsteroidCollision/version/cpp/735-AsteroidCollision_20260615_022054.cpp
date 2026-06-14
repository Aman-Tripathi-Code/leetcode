// Last updated: 6/15/2026, 2:20:54 AM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        stack<int> st;
5        for (int& ast : asteroids) {
6            if (ast > 0) {
7                st.push(ast);
8            } else {
9                while (!st.empty() && st.top() < abs(ast) && st.top() > 0) {
10                    st.pop();
11                }
12                if (st.empty() || st.top() < 0) st.push(ast);
13                else if (st.top() == abs(ast)) {
14                    st.pop();
15                }
16            }
17        }
18        vector<int> ans;
19        while (!st.empty()) {
20            ans.push_back(st.top());
21            st.pop();
22        }
23        reverse(ans.begin(), ans.end());
24        return ans;
25    }
26};