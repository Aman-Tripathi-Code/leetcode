// Last updated: 1/11/2026, 12:59:43 PM
class Solution {
private:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        return a.first - a.second < b.first - b.second;
    }
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {capacity[i],rocks[i]};
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        int i = 0;
        while(additionalRocks && i < n){
            if(additionalRocks >= (v[i].first-v[i].second)){
                additionalRocks -= (v[i].first- v[i].second);
                ans++;
                i++;
            }
            else break;
        }
        return ans;
    }
};