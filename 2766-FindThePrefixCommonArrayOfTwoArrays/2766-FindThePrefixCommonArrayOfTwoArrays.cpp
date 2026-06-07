// Last updated: 6/8/2026, 2:08:04 AM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefix(n,0);
        unsigned long long int aBits = 0, bBits = 0;
        for(int i = 0; i<n; i++){
            aBits |= (1LL << A[i]);
            bBits |= (1LL << B[i]);
            prefix[i] = __builtin_popcountll(aBits & bBits);
        }

        return prefix;
    }
};