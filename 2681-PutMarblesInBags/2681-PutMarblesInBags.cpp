// Last updated: 1/11/2026, 12:59:35 PM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> ans;
        int n = weights.size();
        for(int i = 0; i<n-1; i++){
            ans.push_back(weights[i]+weights[i+1]);
        }
        sort(ans.begin(),ans.end());
        int m = ans.size();
        long long maxi = 0, mini = 0;
        for(int i = 0; i<k-1; i++){
            mini += ans[i];
            maxi += ans[m-1-i];
        }
        return maxi - mini;
    }
};