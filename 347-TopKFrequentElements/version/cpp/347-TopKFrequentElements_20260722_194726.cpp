// Last updated: 7/22/2026, 7:47:26 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        vector<int> ans;
5        int n = nums.size();
6        unordered_map<int,int> mp;
7        for(int i = 0; i<n; i++){
8            mp[nums[i]]++;
9        }
10        priority_queue<pair<int,int>> pq;
11        for(auto &it: mp){
12            pq.push(make_pair(-1*it.second,it.first));
13            if(pq.size() > k){
14                pq.pop();
15            }
16        }
17        while(!pq.empty()){
18            ans.push_back(pq.top().second);
19            pq.pop();
20        }
21        return ans;
22    }
23};