// Last updated: 1/11/2026, 1:00:03 PM
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> pq;
        for(auto it:mp){
            pq.push_back({it.second,it.first});
        }
        sort(pq.begin(),pq.end(),comp);
        vector<int> ans;
        for(auto it:pq){
            while(it.first--){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};