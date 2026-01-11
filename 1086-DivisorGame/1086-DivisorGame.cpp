// Last updated: 1/11/2026, 1:00:40 PM
class Solution {
private: 
    bool f(int n , bool flag){
        if(n==1){
            if(flag==false){
                return false;
            }
            return true;
        }

        for(int i = 1; i<n; i++){
            if(n%i==0){
                bool ans = f(n-i,!flag);
                if(ans==false){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
        return true;
    }
public:
    bool divisorGame(int n) {
        bool flag = false;
        return f(n,flag);
    }
};