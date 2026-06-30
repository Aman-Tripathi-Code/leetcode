// Last updated: 6/30/2026, 10:01:39 PM
1class Solution {
2    public int maxSubArray(int[] nums) {
3        int n = nums.length , maxSum = Integer.MIN_VALUE, curSum = 0;
4        for(int i = 0; i<n; i++){
5            curSum += nums[i];
6            maxSum = Math.max(maxSum, curSum);
7            if(curSum < 0) curSum = 0;
8        }
9        return maxSum;
10    }
11}