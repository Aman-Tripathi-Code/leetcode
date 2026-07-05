// Last updated: 7/5/2026, 1:11:13 PM
1class Solution {
2    public int maxSubArray(int[] nums) {
3        int maxi = Integer.MIN_VALUE, curr = 0, n = nums.length;
4        int tempStart = 0, start = 0, end = 0;
5        for(int i = 0; i<n; i++){
6            curr += nums[i];
7            if(curr > maxi){
8                maxi = curr;
9                start = tempStart;
10                end = i;
11            }
12            if(curr < 0){
13                curr = 0;
14                tempStart = i+1;
15                start = i+1;
16            }
17        }
18        System.out.println("start index is " + start + " end index is " + end);
19        return maxi;
20    }
21}