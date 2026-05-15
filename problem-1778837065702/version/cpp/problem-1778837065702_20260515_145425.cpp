// Last updated: 5/15/2026, 2:54:25 PM
1class Solution {
2public:
3    int maxOperations(vector<int>& nums, int k) {
4        int n = nums.size(), cnt = 0;
5        map<int,int> mp;
6        for(int i = 0; i<n; i++){
7            mp[nums[i]]++;
8        }
9
10        for(int i = 0; i<n; i++){
11            int target = k - nums[i];
12            if(mp.find(target) != mp.end() && mp[target] > 0 && mp[nums[i]] > 0){
13                if(nums[i] == target && mp[nums[i]] < 2){
14                    continue;
15                }
16                cnt++;
17                mp[target] -= 1;
18                mp[nums[i]] -= 1;
19                if(mp[target] == 0){
20                    mp.erase(target);
21                }
22                if(mp[nums[i]] == 0){
23                    mp.erase(nums[i]);
24                }
25            }
26        }
27        return cnt;
28    }
29};