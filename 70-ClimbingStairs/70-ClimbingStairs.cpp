// Last updated: 1/11/2026, 1:03:37 PM
class Solution {
private:
    int recursive(int n){
        if(n==0 || n == 1){
            return 1;
        }
        int oneStep = recursive(n-1);
        int twoStep = recursive(n-2);
        return oneStep+twoStep;
    }
    int bottomUp(int n, vector<int> &dp){
        if(n==0 || n == 1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int oneStep = bottomUp(n-1,dp);
        int twoStep = bottomUp(n-2,dp);
        return dp[n] = oneStep+twoStep;
    }
    void mul(vector<vector<int>> &a, vector<vector<int>> &b){
        vector<vector<int>> c(2,vector<int>(2,0));
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                int sum = 0;
                for(int k = 0; k<2; k++){
                    sum += a[i][k]*b[k][j];
                }
                c[i][j] = sum;
            }
        }
        a = c;
    }
    void matPow(vector<vector<int>> &mat, int pow){
        vector<vector<int>> a(2,vector<int>(2,0));
        a[0][0] = a[1][1] = 1;
        while(pow){
            if(pow%2){
                mul(a,mat);
                pow--;
            }
            else{
                mul(mat,mat);
                pow /= 2; 
            }
        }
        mat = a;
    }
public:
    int climbStairs(int n) {
        //top-down
        vector<int> dp(n+1,-1);
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i<=n ; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        //space optimisation
        int curr = 1, prev = 1;
        int res = 0;
        for(int i = 2; i<=n; i++){
            res = curr + prev;
            prev = curr;
            curr = res;
        }
        //matrix exponentiation 
        vector<vector<int>> I(2,vector<int>(2,1));
        I[0][0] = 0;
        matPow(I,n);
        return I[1][1];
    }
};