// Last updated: 6/15/2026, 2:22:29 AM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        int n = asteroids.size();
5        stack<int> st;
6        for (int i = 0; i<n; i++) {
7            if (asteroids[i] > 0) {
8                st.push(asteroids[i]);
9            } else {
10                while (!st.empty() && st.top() < abs(asteroids[i]) && st.top() > 0) {
11                    st.pop();
12                }
13                if (st.empty() || st.top() < 0) st.push(asteroids[i]);
14                else if (st.top() == abs(asteroids[i])) {
15                    st.pop();
16                }
17            }
18        }
19        vector<int> ans;
20        while (!st.empty()) {
21            ans.push_back(st.top());
22            st.pop();
23        }
24        reverse(ans.begin(), ans.end());
25        return ans;
26    }
27};