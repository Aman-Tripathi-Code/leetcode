// Last updated: 1/11/2026, 1:01:46 PM
class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& sz) {
        int N = greed.size(), M = sz.size();
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        
        int i = 0, j = 0, cnt = 0;
        while(i<N && j<M){
            if(greed[i] <= sz[j]){
                i++;
                j++;
                cnt++;
            }
            else if(greed[i] > sz[j]){
                j++;
            }
            else i++;
        }
        return cnt;
    }
};