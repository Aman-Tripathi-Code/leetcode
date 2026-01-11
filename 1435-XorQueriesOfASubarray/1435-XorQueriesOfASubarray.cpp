// Last updated: 1/11/2026, 1:00:27 PM
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n= arr.size();
        vector<int> preXOR(n);
        preXOR[0] = arr[0];
        for(int i = 1; i<n; i++){
            preXOR[i] = preXOR[i-1]^arr[i];
        }
        int sz = queries.size();
        for(int i = 0; i<sz; i++){
            if(queries[i][0]==0){
                ans.push_back(preXOR[queries[i][1]]);
            }
            else{
                int x = preXOR[queries[i][0]-1] ^ preXOR[queries[i][1]];
                ans.push_back(x);
            }
        }
        return ans;
    }
};