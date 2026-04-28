// Last updated: 4/28/2026, 11:37:53 PM
1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int startIndex) {
4        int n = words.size(), ans = 1e9;
5        for(int i = startIndex; i<(n+startIndex); i++){
6            if(words[i%n] == target){
7                ans = min(ans,min((n-i+startIndex),(i-startIndex)));
8            }
9        }
10        return (ans == 1e9) ? -1 : ans;
11    }
12};