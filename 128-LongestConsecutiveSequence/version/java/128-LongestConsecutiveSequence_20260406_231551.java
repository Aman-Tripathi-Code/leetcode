// Last updated: 4/6/2026, 11:15:51 PM
1class Solution {
2    public int longestConsecutive(int[] nums) {
3        int n = nums.length, maxi = 0;
4        Set<Integer> st = new HashSet<>();
5        for(int x: nums){
6            st.add(x);
7        }
8        for(int x: st){
9            if(st.contains(x-1)){
10                continue;
11            }else{
12                int cnt = x, curr = 0;
13                while(st.contains(cnt)){
14                    cnt++;
15                    curr++;
16                }
17                maxi = Math.max(curr,maxi);
18            }
19        }
20        return maxi;
21    }
22}