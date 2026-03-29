// Last updated: 3/29/2026, 6:11:30 PM
1class Solution {
2public:
3    vector<int> rearrangeArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6        int pos = 0, neg = 1;
7        for(int i = 0; i<n; i++){
8            if(nums[i] >= 0){
9                ans[pos] = nums[i];
10                pos += 2;
11            }else{
12                ans[neg] = nums[i];
13                neg += 2;
14            }
15        }
16        return ans;
17    }
18};