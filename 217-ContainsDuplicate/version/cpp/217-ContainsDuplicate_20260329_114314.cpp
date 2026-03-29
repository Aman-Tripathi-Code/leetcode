// Last updated: 3/29/2026, 11:43:14 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        int n = nums.size();
5        unordered_set<int> st;
6        for(int i = 0; i<n; i++){
7            auto it = st.find(nums[i]);
8            if(it != st.end()){
9                return true;
10            }else{
11                st.insert(nums[i]);
12            }
13        }
14        return false;
15    }
16};