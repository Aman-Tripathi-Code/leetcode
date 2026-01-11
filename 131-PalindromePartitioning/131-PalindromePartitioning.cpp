// Last updated: 1/11/2026, 1:02:58 PM
class Solution {
public:
    bool palindromeCheck(string s, int start ,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void paliPart(int ind,vector<string> &path, vector<vector<string>> &ans, int n,string &s){
        if(ind==n){
            ans.push_back(path);
            return;
        }
        for(int i = ind; i<n; i++){
            if(palindromeCheck(s,ind,i)){
                path.push_back(s.substr(ind,i-ind+1));
                paliPart(i+1,path,ans,n,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        paliPart(0,path,ans,n,s);
        return ans;
    }
};