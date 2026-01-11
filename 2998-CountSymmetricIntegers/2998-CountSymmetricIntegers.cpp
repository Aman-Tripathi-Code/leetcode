// Last updated: 1/11/2026, 12:59:28 PM
class Solution {
public:
    bool is_palindrome(string &s){
        int n = s.size();
        if(n & 1) return false;
        int start = 0, end = 0;
        for(int i = 0; i<n/2; i++){
            start += s[i]-'0';
            end += s[n-1-i]-'0';
        }
        return start == end;
    }
    int check(int n ){
        string num = to_string(n);
        cout << num << endl;
        if(is_palindrome(num)){
            return 1;
        }
        return 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i<=high; i++){
            int numOfdigits = ceil(log10(i));
            if(numOfdigits % 2 == 0){
                count += check(i);
            }
        }
        return count;
    }
};