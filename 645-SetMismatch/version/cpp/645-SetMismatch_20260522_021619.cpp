// Last updated: 5/22/2026, 2:16:19 AM
1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans;
6        for (int i = 0; i < n; i++) {
7            int ind = abs(nums[i]) - 1;
8            nums[ind] = -abs(nums[ind]);
9        }
10        for (int i = 0; i < n; i++) {
11            if (nums[i] > 0) {
12                ans.push_back(i + 1);
13            }
14        }
15
16        return ans;
17    }
18};