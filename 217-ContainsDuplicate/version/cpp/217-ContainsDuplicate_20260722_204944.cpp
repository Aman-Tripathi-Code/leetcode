// Last updated: 7/22/2026, 8:49:44 PM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_set<int> st;
5        int n = nums.size();
6        for(int i = 0; i<n; i++){
7            if(st.find(nums[i]) != st.end()){
8                return true;
9            }
10            st.insert(nums[i]);
11        }
12        return false;
13    }
14};