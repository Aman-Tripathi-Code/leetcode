// Last updated: 6/24/2026, 11:29:46 PM
1class Solution {
2    public int countMajoritySubarrays(int[] nums, int target) {
3        int n = nums.length;
4        int subArrayCount = 0;
5        for(int i = 0; i<n; i++){
6            int majorityElementCount = 0;
7            for(int j = i; j<n; j++){
8                if(target == nums[j]){
9                    majorityElementCount++;
10                }
11                if((majorityElementCount * 2) > (j-i+1)){
12                    subArrayCount++;
13                }
14            }
15        }
16        return subArrayCount;
17    }
18}