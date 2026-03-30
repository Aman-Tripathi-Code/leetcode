// Last updated: 3/30/2026, 2:28:06 PM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int pre = 1, n = nums.size();
5        vector<int> suf(n,1);
6        for(int i = n-2; i>=0;  i--){
7            suf[i] = suf[i+1] * nums[i+1];
8        }
9        vector<int> ans;
10        for(int i = 0; i<n; i++){
11            int curr = pre * suf[i];
12            ans.push_back(curr);
13            pre *= nums[i];
14        }
15        return ans;
16    }
17};