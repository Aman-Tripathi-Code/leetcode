// Last updated: 1/11/2026, 1:01:28 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> hs1(26,0);
        for(auto ch:s1){
            hs1[ch-'a']++;
        }
        vector<int> hs2(26,0);
        int i = 0, j = 0;
        while(j<m){
            hs2[s2[j]-'a']++;
            if(j-i+1==n){
                bool flag = true;
                for(int ind = 0; ind<26; ind++){
                    if(hs1[ind]!=hs2[ind]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }

                hs2[s2[i]-'a']--;
                i++;
            }
            j++;
        }
        
        return false;
    }
};