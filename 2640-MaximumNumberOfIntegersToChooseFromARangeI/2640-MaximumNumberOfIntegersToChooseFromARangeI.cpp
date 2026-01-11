// Last updated: 1/11/2026, 12:59:36 PM
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        sort(banned.begin(),banned.end());
        for(int i = 1; i<=n; i++){
            if(!binary_search(banned.begin(),banned.end(),i) && i<=maxSum){
                count++;
                maxSum -= i;
            }
        }
        return count;
    }
};