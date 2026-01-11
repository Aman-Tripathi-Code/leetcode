// Last updated: 1/11/2026, 1:01:57 PM
class Solution {
private:
    void dfs(int x,int n, vector<int> &ans){
        if(x > n){
            return;
        }
        ans.push_back(x);
        for(int i = 0; i<=9; i++){
            if(x + i > n){
                break;
            }
            dfs(x*10+i,n,ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<=9; i++){
            dfs(i,n,ans);
        }
        return ans;
    }
};