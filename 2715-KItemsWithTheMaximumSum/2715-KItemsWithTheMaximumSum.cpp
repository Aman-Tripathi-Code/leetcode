// Last updated: 1/11/2026, 12:59:34 PM
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = min(k,numOnes);
        k -= min(k,numOnes);
        if(k == 0) return sum;
        k -= min(k,numZeros);
        if(k == 0) return sum;
        sum -= min(k,numNegOnes);
        return sum;
    }
};