// Last updated: 1/11/2026, 1:00:29 PM
class Solution {
    private:
    void recursion(int ind, vector<int> &ds, vector<int>& cookies, int n, int k, int &mini){
        if(ind == n){
            int ans = -1e9;
            for(int i = 0; i<k; i++){
                ans = max(ans,ds[i]);
            }
            mini = min(mini,ans);
            return;
        }

        for(int i = 0; i<k; i++){
            ds[i] += cookies[ind];
            recursion(ind+1,ds,cookies,n,k,mini);
            ds[i] -= cookies[ind]; 
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> ds(k,0);
        int mini = 1e9;
        recursion(0,ds,cookies,n,k,mini);
        return mini;
    }
};