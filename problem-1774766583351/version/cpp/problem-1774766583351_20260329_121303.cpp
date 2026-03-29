// Last updated: 3/29/2026, 12:13:03 PM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int n = nums.size();
5        int left = 0, mid = 0, right = n-1;
6        while(mid <= right){
7            if(nums[mid] == 0){
8                swap(nums[left++],nums[mid++]);
9            }else if(nums[mid] == 1){
10                mid++;
11            }else{
12                swap(nums[right--],nums[mid]);
13            }
14        }
15    }
16};