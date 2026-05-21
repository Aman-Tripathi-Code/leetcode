// Last updated: 5/22/2026, 1:57:45 AM
1class Solution {
2public:
3    vector<int> findDisappearedNumbers(vector<int>& nums) {
4        unordered_set<int> st;
5        for(auto &x: nums){
6            st.insert(x);
7        }
8        vector<int> ans;
9        int n = nums.size();
10        for(int i = 1; i<=n; i++){
11            if(!st.contains(i)){
12                ans.push_back(i);
13            }
14        }
15
16        return ans;
17    }
18};