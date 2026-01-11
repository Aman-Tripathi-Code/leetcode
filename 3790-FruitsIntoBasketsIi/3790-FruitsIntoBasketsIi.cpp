// Last updated: 1/11/2026, 12:59:13 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), cnt = 0;
        vector<int> vis(n,0);
        for(int i = 0; i<n; i++){
            bool found = false;
            for(int j = 0; j<n; j++){
                if(fruits[i] <= baskets[j] && vis[j] == 0){
                    vis[j] = 1;
                    found = true;
                    break;
                }
            }
            if(!found) cnt++;
        }
        return cnt;
    }
};