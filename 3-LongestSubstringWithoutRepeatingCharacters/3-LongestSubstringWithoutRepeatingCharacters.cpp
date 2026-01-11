// Last updated: 1/11/2026, 1:04:19 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0, j = 0, maxi = 0;
    
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size() == j-i+1){
                maxi = max(maxi,j-i+1);
            }
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                maxi = max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};