// Last updated: 6/8/2026, 2:08:26 AM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxi = -1;
        for(int i = 0; i<n; i++){
           if(colors[i] != colors[n-1]){
            maxi = (n-1-i);
            break;
           }
        }
        for(int i = n-1; i>=0; i--){
            if(colors[i] != colors[0]){
                maxi = max(maxi,i);
                break;
            }
        }
        return maxi;
    }
};