// Last updated: 3/29/2026, 11:47:17 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int> st;
5        st.reserve(nums.size());
6        for(int num: nums){
7            if(!st.insert(num).second){
8                return true;
9            }
10        }
11        return false;
12    }
13};