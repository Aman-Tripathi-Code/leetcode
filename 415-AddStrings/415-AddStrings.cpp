// Last updated: 1/11/2026, 1:01:53 PM
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int i = n-1, j = m-1, carry = 0;
        string ans;
        while(i>=0 || j>=0 || carry){
            int x = (i>=0) ? (num1[i]-'0') : 0;
            int y = (j>=0) ? (num2[j]-'0') : 0;
            int sum = x+y+carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum+'0');
            i--; j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};