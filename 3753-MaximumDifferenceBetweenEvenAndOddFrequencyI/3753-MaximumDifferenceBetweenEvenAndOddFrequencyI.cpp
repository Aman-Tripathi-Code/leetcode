// Last updated: 1/11/2026, 12:59:18 PM
class Solution {
public:
    int maxDifference(string s) {
        int hs[26];
        memset(hs,0,sizeof(hs));
        for(auto &it: s){
            hs[it-'a']++;
        }
        int maxO = 0, maxE = 100;
        for(int i = 0; i<26; i++){
            if(hs[i] & 1){
                maxO = max(maxO, hs[i]);
            }
            else{
                if(hs[i] > 0) maxE = min(maxE,hs[i]);
            }
        }
        return maxO - maxE;
    }
};