// Last updated: 5/20/2026, 11:33:51 AM
1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
4        int n = A.size();
5        vector<int> prefix(n,0);
6        unsigned long long int aBits = 0, bBits = 0;
7        for(int i = 0; i<n; i++){
8            aBits |= (1LL << A[i]);
9            bBits |= (1LL << B[i]);
10            prefix[i] = __builtin_popcountll(aBits & bBits);
11        }
12
13        return prefix;
14    }
15};