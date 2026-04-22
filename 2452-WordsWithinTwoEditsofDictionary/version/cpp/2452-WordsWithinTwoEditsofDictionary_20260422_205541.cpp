// Last updated: 4/22/2026, 8:55:41 PM
1class Solution {
2public:
3    //O(n)
4    bool withTwoEdits(string &query, string &dict){
5        int n = query.size(), cnt = 0;
6        for(int i = 0; i<n; i++){
7            if(query[i] != dict[i]){
8                cnt++;
9            }
10            if(cnt >= 3){
11                return false;
12            }
13        }
14        return true;
15    }
16    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
17        vector<string> ans;
18        int qSize = queries.size(), dSize = dictionary.size();
19        //TC - O(qSize* dSize * n);
20        //TC - O(10000* n)
21        for(int i = 0; i<qSize; i++){
22            for(int j = 0; j<dSize; j++){
23                if(withTwoEdits(queries[i], dictionary[j])){
24                    ans.push_back(queries[i]);
25                    break;
26                }
27            }
28        }
29        return ans;
30    }
31};