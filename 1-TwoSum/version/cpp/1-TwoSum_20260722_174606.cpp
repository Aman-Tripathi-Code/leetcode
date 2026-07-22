// Last updated: 7/22/2026, 5:46:06 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        int n = nums.size();
5        unordered_map<int,int> mp;
6        for(int i = 0; i<n; i++){
7            int complement = target - nums[i];
8            if(mp.find(complement) != mp.end()){
9                int targetIndex = mp[complement];
10                return {i,targetIndex};
11            }
12            mp[nums[i]] = i;
13        }
14        return {-1,-1};
15    }
16};