// Last updated: 5/25/2026, 2:01:04 PM
1class Solution {
2public:
3    int tupleSameProduct(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int,int> mp;
6        for(int i = 0; i<n-1; i++){
7            for(int j = i+1; j<n; j++){
8                int prod = nums[i] * nums[j];
9                mp[prod]++;
10            }
11        }
12        int ans = 0;
13        for(auto &it :mp){
14            if(it.second > 1){
15                ans += (it.second * (it.second -1) * 4);
16            }
17        }
18        return ans;
19    }
20};