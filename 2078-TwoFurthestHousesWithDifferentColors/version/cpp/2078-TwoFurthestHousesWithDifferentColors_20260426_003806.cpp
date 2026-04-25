// Last updated: 4/26/2026, 12:38:06 AM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        int n = colors.size();
5        int maxi = -1;
6        for(int i = 0; i<n-1; i++){
7            int diff = 0;
8            for(int j = i+1; j<n; j++){
9                if(colors[i] != colors[j]){
10                    diff = j - i;
11                }
12            }
13            maxi = max(diff, maxi);
14        }
15        return maxi;
16    }
17};