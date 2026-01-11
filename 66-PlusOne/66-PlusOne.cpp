// Last updated: 1/11/2026, 1:03:39 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 0;
        if(digits[n-1] != 9){
            digits[n-1] += 1;
        }
        else{
            digits[n-1] = 0;
            carry = 1;
            int i = n-2;
            while(carry && i >= 0){
                if(digits[i] != 9){
                    carry = 0;
                    digits[i] += 1;
                }else{
                    digits[i] = 0;
                }
                i--;
                // cout << i << ' ' << digits[i] << endl;
            }
            // for(auto &it: digits){
            //     cout << it << ' ';
            // }
            if(carry){
                digits.resize(n+1);
                for(int i = n; i>0 ; i--){
                    digits[i] = digits[i-1];
                }
                digits[0] = 1;
            }
        }
        return digits;
    }
};