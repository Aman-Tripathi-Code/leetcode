// Last updated: 1/11/2026, 1:02:56 PM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0, totalGas =0;
        int len = cost.size();
        for(int i = 0; i<len ; i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost>totalGas){
            return -1;
        }
        int ind = 0, curr = 0;
        for(int i = 0; i<len ; i++){
            curr += gas[i]-cost[i];
            if(curr<0){
                ind = i+1;
                curr = 0;
            }
        }
        if(ind>=len){
            return -1;
        }
        return ind;
    }
};