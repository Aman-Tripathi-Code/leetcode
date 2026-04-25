// Last updated: 4/25/2026, 10:00:26 PM
1class Solution {
2public:
3    int characterReplacement(string s, int k) {
4        int n = s.size();
5        int head = -1, tail = 0, ans = 0, maxFreq = 0;
6        vector<int> freq(26,0);
7
8        while(tail < n){
9            while((head + 1 < n) && (((head - tail + 1 - maxFreq) < k) || (freq[s[head+1]-'A'] == maxFreq))){
10                head++;
11                freq[s[head]-'A']++;
12                maxFreq = max(maxFreq,freq[s[head]-'A']);
13            }
14
15            ans = max(ans, (head - tail + 1));
16
17            if(tail > head){
18                tail++;
19                head = tail - 1;
20            }else{
21                freq[s[tail]-'A']--;
22                maxFreq = max(maxFreq,freq[s[tail]-'A']);
23                tail++;
24            }
25        }
26        return ans;
27    }
28};