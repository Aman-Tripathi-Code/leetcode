// Last updated: 3/29/2026, 12:30:43 AM
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int n = nums.size();
5        int curr = 0, maxi = 0;
6        for(int i = 0; i<n; i++){
7            if(nums[i] == 1){
8                curr++;
9            }else{
10                curr = 0;
11            }
12            maxi = max(curr, maxi);
13        }
14        return maxi;
15    }
16};