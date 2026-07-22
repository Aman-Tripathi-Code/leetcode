// Last updated: 7/23/2026, 1:23:07 AM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4        set<int> st;
5        int n = nums.size();
6        for(int i = 0; i<n; i++){
7            st.insert(nums[i]);
8        }
9        int maxi = 0;
10        for(auto &x: st){
11            int curr = x;
12            if(st.find(curr+1) == st.end()){
13                int cnt = 0;
14                while(st.find(curr) != st.end()){
15                    cnt++;
16                    curr--;
17                }
18                maxi = max(cnt, maxi);
19            }
20        }
21
22        return maxi;
23        
24    }
25};