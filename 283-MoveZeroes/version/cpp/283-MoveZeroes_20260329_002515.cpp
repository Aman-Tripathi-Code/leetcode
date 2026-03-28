// Last updated: 3/29/2026, 12:25:15 AM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int n = nums.size(), j = 0;
5        for(int i = 0; i<n; i++){
6            if(nums[i] != 0){
7                nums[j] = nums[i];
8                j++;
9            }
10        }
11        while(j < n){
12            nums[j++] = 0;
13        }
14    }
15};