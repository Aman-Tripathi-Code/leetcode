// Last updated: 7/11/2026, 3:26:28 AM
1class Solution {
2    private void swap(int[] nums, int i, int j){
3        int temp = nums[i];
4        nums[i] = nums[j];
5        nums[j] = temp;
6    }
7    public void sortColors(int[] nums) {
8        int n = nums.length;
9        int lo = 0, mid = 0, hi = n-1;
10
11        while(mid <= hi){
12            if(nums[mid] == 0){
13                swap(nums,mid,lo);
14                mid++;
15                lo++;
16            }else if(nums[mid] == 1){
17                mid++;
18            }else{
19                swap(nums,mid,hi);
20                hi--;
21            }
22        }
23    }
24}