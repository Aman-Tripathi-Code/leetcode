// Last updated: 1/11/2026, 12:59:22 PM
class Solution {
public:
    int maxOperations(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.size(), ans = 0;
        int oneCount = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                oneCount++;
            }
            else if (i > 0 && s[i - 1] == '1') {
                ans += oneCount;
            }
        }
        return ans;
    }
};