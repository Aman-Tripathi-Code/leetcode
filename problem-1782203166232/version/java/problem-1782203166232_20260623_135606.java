// Last updated: 6/23/2026, 1:56:06 PM
1class Solution {
2    public int[] twoSum(int[] nums, int target) {
3        int n = nums.length;
4        int[] pairSumEqualTarget = new int[]{-1,-1};
5        Map<Integer,Integer> elementIndexMap  = new HashMap<>();
6        for(int i = 0; i<n; i++){
7            if(elementIndexMap.containsKey(target-nums[i])){
8                int diffIndex = elementIndexMap.get(target-nums[i]);
9                pairSumEqualTarget = new int[]{i,diffIndex};
10                break;
11            }
12            elementIndexMap.put(nums[i],i);
13        }
14        return pairSumEqualTarget;
15    }
16}