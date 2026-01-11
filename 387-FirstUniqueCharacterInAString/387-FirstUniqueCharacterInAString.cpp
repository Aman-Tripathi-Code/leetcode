// Last updated: 1/11/2026, 1:01:56 PM
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        int ind = -1;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(mp[s[i]]==1){
                ind = i;
                break;
            }
        }
        return ind;
    }
};