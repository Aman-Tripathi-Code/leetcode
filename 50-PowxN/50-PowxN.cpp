// Last updated: 1/11/2026, 1:03:48 PM
class Solution {
private:
    double binPow(double n, int pow){
        if(pow==0){
            return 1;
        }
        double res = binPow(n,pow/2);
        if(pow%2){
            return res*res*n;
        }
        else return res*res;   
    }
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n<0){
            n = abs(n);
            return 1.0/binPow(x,n);
        }
        return binPow(x,n);
    }
};