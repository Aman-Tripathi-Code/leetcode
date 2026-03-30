// Last updated: 3/30/2026, 2:33:35 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int pre = 1, n = nums.size();
5        vector<int> ans(n,1);
6        for(int i = n-2; i>=0;  i--){
7            ans[i] = ans[i+1] * nums[i+1];
8        }
9        for(int i = 0; i<n; i++){
10            ans[i] = pre * ans[i];
11            pre *= nums[i];
12        }
13        return ans;
14    }
15};