// Last updated: 7/23/2026, 10:48:16 AM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size(), maxi = 0;
5        unordered_map<char,int> mp;
6        int i = 0, j = 0;
7        while(j < n){
8            mp[s[j]]++;
9            if((j-i+1) > mp.size()){
10                while((j-i+1) > mp.size()){
11                    mp[s[i]]--;
12                    if(mp[s[i]] == 0){
13                        mp.erase(s[i]);
14                    }
15                    i++;
16                }
17            }
18            maxi = max(maxi,(j-i+1));
19            j++;
20        }
21        return maxi;
22    }
23};