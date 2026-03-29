// Last updated: 3/29/2026, 11:44:13 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        int n = nums.size();
5        unordered_set<int> st;
6        st.reserve(n);
7        for(int i = 0; i<n; i++){
8            auto it = st.find(nums[i]);
9            if(it != st.end()){
10                return true;
11            }else{
12                st.insert(nums[i]);
13            }
14        }
15        return false;
16    }
17};