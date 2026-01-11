// Last updated: 1/11/2026, 1:01:50 PM
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> hs1(26,0);
        vector<int> hs2(26,0);

        for(int i = 0; i<m; i++){
            hs2[p[i]-'a']++;
        }

        int i = 0, j = 0;
        vector<int> ans;

        while(j<n){
            hs1[s[j]-'a']++;
            if(j-i+1==m){
                bool flag = true;
                for(int ind = 0; ind<26; ind++){
                    if(hs1[ind]!=hs2[ind]){
                        flag = false;
                    }
                }
                if(flag == true){
                    ans.push_back(i);
                }
                hs1[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};