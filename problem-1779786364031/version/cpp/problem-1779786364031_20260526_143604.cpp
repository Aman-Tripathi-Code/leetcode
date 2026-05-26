// Last updated: 5/26/2026, 2:36:04 PM
1class Solution {
2public:
3    int kthLargestValue(vector<vector<int>>& matrix, int k) {
4        int n = matrix.size(), m = matrix.front().size(); 
5        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
6        for(int i = 1; i<=n; i++){
7            for(int j = 1; j<=m; j++){
8                prefix[i][j] = (matrix[i-1][j-1] ^ prefix[i-1][j] ^ prefix[i][j-1] ^ prefix[i-1][j-1]);
9            }            
10        }
11
12        priority_queue<int> pq;
13        for(int i = 1; i<=n; i++){
14            for(int j = 1; j<=m; j++){
15                pq.push(-1*prefix[i][j]);
16                if(pq.size() > k){
17                    pq.pop();
18                }
19            }
20        }
21        return -1*pq.top();
22    }
23};