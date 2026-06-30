// Last updated: 6/30/2026, 8:39:25 PM
1class Solution {
2    public int[] twoSum(int[] nums, int target) {
3        Map<Integer,Integer> numIndMap = new HashMap<>();
4        int[] pair = new int[2];
5        int n = nums.length;
6
7        for(int i = 0; i<n; i++){
8            int complement = target - nums[i];
9            if(numIndMap.containsKey(complement)){
10                pair[0] = i;
11                pair[1] = numIndMap.get(complement);
12                return pair;
13            }
14            numIndMap.put(nums[i],i);
15        }
16        return pair;
17    }
18}