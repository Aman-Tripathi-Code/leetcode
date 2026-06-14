// Last updated: 6/15/2026, 2:14:28 AM
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
12                if (st.empty() || st.top() < 0)
13                    st.push(ast);
14                else {
15                    if (st.top() == abs(ast)) {
16                        st.pop();
17                        continue;
18                    }
19                }
20            }
21        }
22        vector<int> ans;
23        while (!st.empty()) {
24            ans.push_back(st.top());
25            st.pop();
26        }
27        reverse(ans.begin(),ans.end());
28        return ans;
29    }
30};