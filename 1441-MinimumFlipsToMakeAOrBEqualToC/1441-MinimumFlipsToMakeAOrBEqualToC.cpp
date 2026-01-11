// Last updated: 1/11/2026, 1:00:25 PM
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        for(int i = 0; i<32; i++){
            int x = false, y = false, z = false;
            if(a & 1<<i) x = true;
            if(b & 1<<i) y = true;
            if(c & 1<<i) z = true;
            if(x == y && x == true && !z){
                count += 2;
            }
            else if(x == y && x == false && z){
                count += 1;
            }
            else if(x != y && !z){
                count += 1;
            }
        }
        return count;
    }
};