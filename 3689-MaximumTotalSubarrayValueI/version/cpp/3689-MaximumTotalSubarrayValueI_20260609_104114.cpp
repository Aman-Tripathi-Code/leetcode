// Last updated: 6/9/2026, 10:41:14 AM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int mini = INT_MAX, maxi = INT_MIN;
5        for(int &n: nums){
6            mini = min(n,mini);
7            maxi = max(n,maxi);
8        }
9        return k * 1LL * (maxi-mini);
10    }
11};