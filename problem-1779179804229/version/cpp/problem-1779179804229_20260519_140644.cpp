// Last updated: 5/19/2026, 2:06:44 PM
1class Solution {
2public:
3    int maximumUniqueSubarray(vector<int>& nums) {
4        int n = nums.size();
5        unordered_map<int,int> mp;
6        int i = 0, j = 0;
7        int ans = 0, curr = 0;
8
9        while(j < n){
10            mp[nums[j]]++;
11            curr += nums[j];
12            if(mp.size() == (j-i+1)){
13                ans = max(ans,curr);
14            }
15            else{
16                while(mp.size() < (j-i+1)){
17                    mp[nums[i]]--;
18                    curr -= nums[i];
19                    if(mp[nums[i]] == 0){
20                        mp.erase(nums[i]);
21                    }
22                    i++;
23                }
24                ans = max(ans,curr);
25            }
26            j++;
27        }
28        return ans;
29    }
30};