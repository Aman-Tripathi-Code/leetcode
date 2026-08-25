// Last updated: 8/25/2026, 11:26:20 AM
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4        int n = nums.size();bool hs[101] = {};for(int i = 0; i<n; i++){if(nums[i] % k == 0){hs[nums[i]] = true;}}for(int i = k; i<=100; i+=k){if(hs[i] == false){return i;}}return ((100/k)+1) * k;
5    }
6};