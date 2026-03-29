// Last updated: 3/29/2026, 11:46:18 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        int n = nums.size();
5        unordered_set<int> st;
6        st.reserve(n);
7        for(int i = 0; i<n; i++){
8            if(!st.insert(nums[i]).second){
9                return true;
10            }
11        }
12        return false;
13    }
14};