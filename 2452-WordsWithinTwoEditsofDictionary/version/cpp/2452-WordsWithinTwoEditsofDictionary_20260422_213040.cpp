// Last updated: 4/22/2026, 9:30:40 PM
1class Solution {
2public:
3    // O(n)
4    bool withinTwoEdits(const string& query, const string& dict) {
5        int n = query.size(), numOfEdits = 0;
6        for (int i = 0; i < n; i++) {
7            if (query[i] != dict[i]) {
8                numOfEdits++;
9                if (numOfEdits > 2) {
10                    return false;
11                }
12            }
13        }
14        return true;
15    }
16    vector<string> twoEditWords(vector<string>& queries,
17                                vector<string>& dictionary) {
18        vector<string> result;
19        for(string query : queries){
20            for(string word : dictionary) {
21                if (withinTwoEdits(query, word)) {
22                    result.push_back(query);
23                    break;
24                }
25            }
26        }
27        return result;
28    }
29};