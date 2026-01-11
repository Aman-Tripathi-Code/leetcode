// Last updated: 1/11/2026, 1:00:12 PM
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int cnt = 0, mini = 0, n = target.size();
        for(int i = 0; i<n; i++){
            if(target[i] > mini){
                cnt += (target[i] - mini);
            }
            mini = target[i];
        }
        return cnt;
    }
};