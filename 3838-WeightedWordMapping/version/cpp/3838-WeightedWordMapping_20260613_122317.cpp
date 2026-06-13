// Last updated: 6/13/2026, 12:23:17 PM
1auto init = [](){
2    std::ios_base::sync_with_stdio(false);
3    cin.tie(nullptr); cout.tie(nullptr);
4};
5class Solution {
6public:
7    string mapWordWeights(vector<string>& words, vector<int>& weights) {
8        string ans;
9        ans.reserve(words.size());
10        for(string &s: words){
11            int curr = 0;
12            for(char ch: s){
13                curr += weights[ch-'a'];
14            }
15            curr = curr % 26;
16            ans.push_back('z'-curr);
17        }
18        return ans;
19    }
20};