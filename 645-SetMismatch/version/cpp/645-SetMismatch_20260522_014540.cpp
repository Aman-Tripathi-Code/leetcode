// Last updated: 5/22/2026, 1:45:40 AM
1class Solution {
2public:
3    vector<int> findErrorNums(vector<int>& nums) {
4        int n = nums.size();
5        int xr = 0;
6        for(int i = 0; i<n; i++){
7            xr ^= nums[i];
8            xr ^= (i+1);
9        }
10        int set = 1 << __builtin_ctz(xr);
11        int first = 0, second = 0;
12        for(int i = 0; i<n; i++){
13            if(nums[i] & set){
14                first ^= nums[i];
15            }else{
16                second ^= nums[i];
17            }
18            if((i + 1) & set){
19                first ^= (i+1);
20            }else{
21                second ^= (i+1);
22            }
23        }
24        for(int i = 0; i<n; i++){
25            if(nums[i] == second) return {second, first};
26        }
27        return {first, second};
28    }
29};