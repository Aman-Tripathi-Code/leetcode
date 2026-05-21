// Last updated: 5/21/2026, 2:48:25 PM
1class Solution {
2public:
3    static bool cmp(vector<int>&a , vector<int> &b){
4        return a[1] > b[1];
5    }
6    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
7        sort(boxTypes.begin(),boxTypes.end(),cmp);
8        int n = boxTypes.size() , ans = 0;
9        for(int i =0 ; i<n && truckSize > 0; i++){
10            int numOfBoxes = min(truckSize,boxTypes[i][0]);
11            int numOfUnits = boxTypes[i][1];
12            ans += numOfBoxes * numOfUnits;
13            truckSize -= numOfBoxes;
14        }
15
16        return ans;
17        
18    }
19};