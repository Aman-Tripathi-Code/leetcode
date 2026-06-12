// Last updated: 6/12/2026, 9:49:51 PM
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans;
5        for(string &s: words){
6            int curr = 0;
7            for(char ch: s){
8                curr += weights[ch-'a'];
9            }
10            curr = curr % 26;
11            ans.push_back('z'-curr);
12        }
13        return ans;
14    }
15};