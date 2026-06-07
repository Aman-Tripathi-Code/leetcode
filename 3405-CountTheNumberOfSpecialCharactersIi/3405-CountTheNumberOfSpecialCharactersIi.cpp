// Last updated: 6/8/2026, 2:07:50 AM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int small = 0, cap = 0;
        for(char &ch: word){
            int shift = 0;
            if(ch >= 'a' && ch <= 'z'){
                shift = 1 << (ch - 'a');
                small = (cap & shift) ? ((small & shift) ? (small ^ shift) : small) : (small | shift);
            }
            if(ch >= 'A' && ch <= 'Z'){
                shift = 1 << (ch - 'A');
                cap |= shift;
            }
        }
        return __builtin_popcount(small&cap);
    }
};