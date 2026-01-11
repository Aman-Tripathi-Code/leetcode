// Last updated: 1/11/2026, 12:59:40 PM
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long int> mp;
        for(int i = 0; i<edges.size(); i++){
            mp[edges[i]] += i;
        }
        int maxi = 0 , ind = -1;
        for(auto k:mp){
            if(k.second>maxi){
                maxi = k.second;
                ind = k.first;
            }
        }
        return ind;
    }
};