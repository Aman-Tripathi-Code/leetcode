// Last updated: 6/8/2026, 11:06:07 PM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int mini = INT_MAX, maxi = INT_MIN;
5        for(int &n: nums){
6            if(n < mini) mini = n;
7            if(n > maxi) maxi = n;
8        }
9        return k * 1LL * (maxi-mini);
10    }
11};