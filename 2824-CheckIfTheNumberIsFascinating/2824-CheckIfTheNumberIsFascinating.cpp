// Last updated: 1/11/2026, 12:59:31 PM
class Solution {
public:
    bool isFascinating(int n) {
        int a = n, b = 2*n, c = 3*n;
        int freq[9];
        memset(freq,0,sizeof(freq));
        while(a){
            int rem = a % 10;
            if(rem != 0)  freq[rem-1]++;
            a /= 10;
        }
        while(b){
            int rem = b % 10;
            if(rem != 0)  freq[rem-1]++;
            b /= 10;
        }
        while(c){
            int rem = c % 10;
            if(rem != 0)  freq[rem-1]++;
            c /= 10;
        }
        for(int i = 0; i<9; i++){
            if(freq[i] != 1) return false;
        }
        return true;
    }
};