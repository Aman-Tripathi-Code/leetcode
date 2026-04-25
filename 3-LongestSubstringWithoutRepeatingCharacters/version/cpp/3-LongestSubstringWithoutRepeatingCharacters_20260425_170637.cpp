// Last updated: 4/25/2026, 5:06:37 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.size();
5        int head = -1, tail = 0;
6        int ans = 0;
7        map<char,int> mp;
8        
9        while(tail < n){
10            while((head + 1 < n) && (mp[s[head + 1]] == 0)){
11                head++;
12                mp[s[head]]++;
13            }
14
15            ans = max(ans, (head - tail + 1));
16
17            if(tail > head){
18                tail++;
19                head - 1;
20            }else{
21                mp[s[tail]]--;
22                tail++;
23            }
24        }
25        return ans;
26    }
27};