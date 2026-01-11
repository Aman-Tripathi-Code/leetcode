// Last updated: 1/11/2026, 1:04:16 PM
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign  = 1, base = 0, i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i++] == '-') ? -1 : 1;
        }
        cout << sign << " "<< i << endl;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            if(base > INT_MAX/10 || (base == INT_MAX/10 && s[i] - '0' > 7)){
                if(sign == 1) return INT_MAX;
                return INT_MIN;
            }
            base = (10 * base) + (s[i] - '0');
            i++;
        }
        return base*sign;
    }
};