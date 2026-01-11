// Last updated: 1/11/2026, 1:01:47 PM
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        int i = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int freq = it.first;
            char ch = it.second;

            while(freq--){
                s[i] = ch;
                i++;
            }
        }
        return s;
    }
};