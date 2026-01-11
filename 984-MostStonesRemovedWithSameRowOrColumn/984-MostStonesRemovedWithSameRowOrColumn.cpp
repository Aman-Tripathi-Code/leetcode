// Last updated: 1/11/2026, 1:00:54 PM
class Solution {
private:
    int findPar(int a,int par[]){
        if(a==par[a]){
            return a;
        }
        return par[a] = findPar(par[a],par);
    }
    void makeUnion(int x, int y,int par[],int rank[]){
        int xPar = findPar(x,par);
        int yPar = findPar(y,par);
        if(xPar == yPar){
            return;
        }
        else if(rank[xPar]>rank[yPar]){
            par[yPar] = xPar;
        }
        else if(rank[yPar]>rank[xPar]){
            par[xPar] = yPar;
        }
        else{
            par[yPar] = xPar;
            rank[xPar]++;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m= 0;
        int cntOfStones = stones.size();
        for(auto it:stones){
            n = max(n,it[0]+1);
            m = max(m,it[1]+1);
        }
        int par[n+m],rank[n+m];
        for(int i = 0; i<n+m; i++){
            par[i] = i;
            rank[i] = 0;
        }
        for(auto it:stones){
            int i = it[0];
            int j = it[1]+n;
            makeUnion(i,j,par,rank);
        }
        int cnt = 0;
        for(int i = 0; i<n+m; i++){
            if(par[i]==i && rank[i]>0){
                cnt++;
            }
        }
        return cntOfStones-cnt;
    }
};