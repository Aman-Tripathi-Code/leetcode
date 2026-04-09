// Last updated: 4/9/2026, 11:01:14 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        int n = nums.size();
5        int curr = 0, cnt = 0;
6        unordered_map<int,int> mp;
7        mp[0]++;
8        for(int i = 0; i<n; i++){
9            curr += nums[i];
10            int diff = curr - k;
11            if(mp.find(diff) != mp.end()){
12                cnt += mp[diff];
13            }
14            else if(curr == k) cnt++;
15            mp[curr]++;
16        }
17        return cnt;
18    }
19};