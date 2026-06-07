// Last updated: 6/8/2026, 2:07:27 AM
class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), flip = 0;
        int totalCount = count(s.begin(),s.end(),'0');
        vector<int> zero(n, 0);
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (ind == -1) {
                    ind = i;
                }else if(ind == 0){
                    if(totalCount - zero[i-1]){
                        flip++;
                    }
                    else ind = i;
                }else {
                    if (zero[i-1] >= 1) {
                        flip++;
                    }
                    else ind = i;
                }
                if(i > 0)zero[i] = zero[i - 1];
            } else {
                if (i == 0) {
                    zero[i] = 1;
                    continue;
                } else {
                    zero[i] = zero[i - 1] + 1;
                }
            }
        }
        if(totalCount < flip) flip = totalCount;
        return flip;
    }
};