// Last updated: 6/8/2026, 11:04:40 PM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        return k * 1LL * (*max_element(nums.begin(),nums.end()) - *min_element(nums.begin(),nums.end()));
5    }
6};