// Last updated: 6/13/2026, 12:11:51 PM
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans;
5        ans.reserve(words.size());
6        for(string &s: words){
7            int curr = 0;
8            for(char ch: s){
9                curr += weights[ch-'a'];
10            }
11            curr = curr % 26;
12            ans.push_back('z'-curr);
13        }
14        return ans;
15    }
16};