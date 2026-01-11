// Last updated: 1/11/2026, 1:01:19 PM
class Solution {
private:
    int findPar(int x, int par[]){
        if(x==par[x]){
            return x;
        }
        return par[x] = findPar(par[x],par);
    }
    void makeUnion(int x, int y, int par[], int rank[]){
        int xPar = findPar(x,par);
        int yPar = findPar(y,par);
        if(rank[x]>rank[y]){
            par[yPar] = xPar;
        }
        else if(rank[y]>rank[x]){
            par[xPar] = yPar;
        }
        else{
            par[yPar] = xPar;
            rank[xPar]++;
        }
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        int par[n],rank[n];
        for(int i = 0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
        }

        unordered_map<string,int> mp;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string s = accounts[i][j];
                if(mp.find(s)==mp.end()){
                    mp[s] = i;
                }
                else{
                    int k = mp[s];
                    makeUnion(i,k,par,rank);
                }
            }
        }

        vector<string> nodeString[n];

        for(auto it:mp){
            string str = it.first;
            int ind = it.second;
            int parInd = findPar(ind,par);
            nodeString[parInd].push_back(str); 
        }

        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){
            if(nodeString[i].size()==0){
                continue;
            }            
            sort(nodeString[i].begin(), nodeString[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:nodeString[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};