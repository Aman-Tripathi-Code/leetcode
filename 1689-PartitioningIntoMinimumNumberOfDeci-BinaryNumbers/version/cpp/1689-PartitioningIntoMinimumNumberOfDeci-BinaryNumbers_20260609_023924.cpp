// Last updated: 6/9/2026, 2:39:24 AM
1class Solution {
2public:
3    int minPartitions(string n) {
4        int len = n.size();
5        int maxi = 0;
6        for(int i =0 ; i<len; i++){
7            maxi = max(maxi,(n[i]-'0'));
8        }
9        return maxi;
10    }
11};