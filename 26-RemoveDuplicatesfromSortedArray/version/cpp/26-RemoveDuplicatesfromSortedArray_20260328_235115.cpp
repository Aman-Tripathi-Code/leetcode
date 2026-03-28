// Last updated: 3/28/2026, 11:51:15 PM
1class Solution {
2public:
3    int removeDuplicates(vector<int>& nums) {
4        int n = nums.size(),j = 1;
5        for(int i = 1; i<n; i++){
6            if(nums[i] != nums[i-1]){
7                nums[j] = nums[i];
8                j++;
9            }
10        }
11        return j;
12    }
13};