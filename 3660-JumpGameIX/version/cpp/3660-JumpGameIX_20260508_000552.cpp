// Last updated: 5/8/2026, 12:05:52 AM
1class Solution {
2public:
3    struct Item {
4        int value;
5        int left;
6        int right;
7    };
8
9    vector<int> maxValue(const vector<int>& nums) {
10        int n = nums.size();
11        vector<int> ans(n, 0);
12
13        vector<Item> stack;
14
15        for (int i = 0; i < n; ++i) {
16            Item curr = {nums[i], i, i};
17
18            while (!stack.empty() && stack.back().value > nums[i]) {
19                Item top = stack.back();
20                stack.pop_back();
21                curr.value = max(curr.value, top.value);
22                curr.left = top.left;
23            }
24
25            stack.push_back(curr);
26        }
27
28        for (size_t i = 0; i < stack.size(); ++i) {
29            for (int j = stack[i].left; j <= stack[i].right; ++j) {
30                ans[j] = stack[i].value;
31            }
32        }
33
34        return ans;
35    }
36};