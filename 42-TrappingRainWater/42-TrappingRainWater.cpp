// Last updated: 1/11/2026, 1:03:54 PM
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int pre[n];
        int suf[n];
        int mini = -1e9;
        for(int i = 0;i<n; i++){
            mini = max(mini,height[i]);
            pre[i] = mini;
        }
        mini = -1e9;
        for(int i = n-1; i>=0; i--){
            mini = max(mini,height[i]);
            suf[i] = mini;
        }
        vector<int> water(n);
        for(int i = 0; i<n; i++){
            water[i] = min(pre[i],suf[i]) - height[i];
        }

        int sum = 0;

        for(auto it:water){
            sum += it;
        }

        return sum;
    }
};