// Last updated: 4/26/2026, 12:45:17 AM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int maxi = -1;
6        for(int i = 0; i<n; i++){
7           if(colors[i] != colors[n-1]){
8            maxi = (n-1-i);
9            break;
10           }
11        }
12        for(int i = n-1; i>=0; i--){
13            if(colors[i] != colors[0]){
14                maxi = max(maxi,i);
15                break;
16            }
17        }
18        return maxi;
19    }
20};