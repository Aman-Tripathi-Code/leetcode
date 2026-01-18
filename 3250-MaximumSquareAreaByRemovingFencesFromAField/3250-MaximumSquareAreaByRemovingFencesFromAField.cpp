// Last updated: 1/18/2026, 12:52:16 PM
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int sz1 = hFences.size(), sz2 = vFences.size();

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int> st;

        int ans = -1, mod = 1e9+7;
        for(int i = 0; i<sz2-1; i++){
            for(int j = i+1; j<sz2; j++){
                int diff = vFences[j] - vFences[i];
                st.insert(diff);
            }
        }
        for(int i = 0; i<sz1-1; i++){
            for(int j = i+1; j<sz1; j++){
                int diff = hFences[j] - hFences[i];
                if(st.contains(diff)){
                    ans = max(ans, diff);
                }
            }
        }
        ans = (ans != -1) ? ((ans % mod) *1LL * (ans % mod)) % mod : -1;
        return ans;
    }
};