// Last updated: 6/9/2026, 9:16:40 PM
1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int,vector<int>> mp;
6        for(int i = 0; i<n; i++){
7            mp[nums[i]].push_back(i);
8        }
9        int mini = 1e9;
10        for(auto &it: mp){
11            int len = it.second.size();
12            vector<int> v = it.second;
13            if(len >= 3){
14                for(int i = 0; i < (len-2); i++){
15                    int curr = (abs(v[i] - v[i+1]) + abs(v[i+1] - v[i+2]) + abs(v[i+2] - v[i]));
16                    mini = min(mini,curr);
17                }
18            }
19        }
20        return (mini == 1e9) ? -1 : mini;
21    }
22};