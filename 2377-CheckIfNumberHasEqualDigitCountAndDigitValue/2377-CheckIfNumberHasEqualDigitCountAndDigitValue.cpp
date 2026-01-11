// Last updated: 1/11/2026, 12:59:42 PM
class Solution {
public:
    bool digitCount(string num) {
        vector<int>  arr(10);
        for(int i = 0; i<num.size(); i++){
            int n = num[i]-48;
            arr[n]++;
        }
        for(int i = 0; i<num.size() ; i++){
            int n = num[i]-48;
            if(n!=arr[i]){
                return false;
            }
        }
        return true;
    }
};