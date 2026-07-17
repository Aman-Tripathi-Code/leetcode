// Last updated: 7/17/2026, 10:12:39 PM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        int mini = *min_element(nums.begin(),nums.end()), 
5        maxi = *max_element(nums.begin(),nums.end());
6
7        return __gcd(mini,maxi);
8    }
9};