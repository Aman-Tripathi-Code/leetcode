// Last updated: 6/8/2026, 2:08:21 AM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int ans = 0;
        for(int i = 0; i<n; i++){
            if((i+1)%3 != 0){
                ans += cost[i];
            }
        }
        return ans;
    }
};