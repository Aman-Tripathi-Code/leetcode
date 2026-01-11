// Last updated: 1/11/2026, 1:00:06 PM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), i = 0;
        int totSum = accumulate(neededTime.begin(),neededTime.end(),0), reqSum = 0;
        while(i < n){
            if(i < n-1 && colors[i] == colors[i+1]){
                int maxCost = 0;
                while(i < n-1 && colors[i] == colors[i+1]){
                    maxCost = max({maxCost, neededTime[i], neededTime[i+1]});
                    i++;
                }   
                reqSum += maxCost;
                i++;
            }
            else{
                reqSum += neededTime[i];
                i++;
            }
        }
        return totSum - reqSum;
    }
};