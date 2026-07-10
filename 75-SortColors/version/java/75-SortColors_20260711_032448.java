// Last updated: 7/11/2026, 3:24:48 AM
1class Solution {
2    public void sortColors(int[] nums) {
3        int n = nums.length;
4        int lo = 0, mid = 0, hi = n-1;
5
6        while(mid <= hi){
7            if(nums[mid] == 0){
8                int temp = nums[mid];
9                nums[mid] = nums[lo];
10                nums[lo] = temp;
11                mid++;
12                lo++;
13            }else if(nums[mid] == 1){
14                mid++;
15            }else{
16                int temp = nums[mid];
17                nums[mid] = nums[hi];
18                nums[hi] = temp;
19                hi--;
20            }
21        }
22    }
23}