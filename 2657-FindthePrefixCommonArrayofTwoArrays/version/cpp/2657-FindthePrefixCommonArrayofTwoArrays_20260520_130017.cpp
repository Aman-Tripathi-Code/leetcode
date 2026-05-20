// Last updated: 5/20/2026, 1:00:17 PM
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        vector<int> ans;
5        int count = 0;
6        unordered_set<int> s1, s2;
7        int n = A.size();
8        for(int i = 0; i<n; i++){
9            s1.insert(A[i]);
10            s2.insert(B[i]);
11            if(A[i] == B[i]){
12                ++count;
13                ans.push_back(count);
14                continue;
15            }
16            if(s1.contains(B[i])){
17                ++count;
18            }
19            if(s2.contains(A[i])){
20                ++count;
21            }
22            ans.push_back(count);
23        }
24        return ans;
25    }
26};