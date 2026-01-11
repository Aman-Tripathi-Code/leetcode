// Last updated: 1/11/2026, 1:01:20 PM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while(i<n){
            if(bits[i] == 1 && i == n-2){
                return false;
            }
            if(bits[i] == 1){
                i += 2;
            }
            else if(bits[i] == 0){
                i += 1;
            }
        }
        return true;
    }
};