// Last updated: 7/4/2026, 2:49:51 AM
1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int i = 0, j = 0, n = s.length(), ans = 0;
5        map<char,int> freq;
6        while(j < n){
7            freq[s[j]]++;
8            if(freq.size() == 3){
9                while(freq.size() == 3){
10                    ans += (n-j);
11                    freq[s[i]]--;
12                    if(freq[s[i]] == 0){
13                        freq.erase(s[i]);
14                    }
15                    i++;
16                }
17            }
18            j++;
19        }
20        return ans;
21    }
22};