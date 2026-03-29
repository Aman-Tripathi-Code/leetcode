// Last updated: 3/29/2026, 5:52:41 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int sum = 0, maxi = INT_MIN;
5        for(int num: nums){
6            sum += num;
7            maxi = max(maxi,sum);
8            sum = max(sum,0);
9        }
10        return maxi;
11    }
12};