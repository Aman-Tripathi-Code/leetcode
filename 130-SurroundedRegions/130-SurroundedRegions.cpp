// Last updated: 1/11/2026, 1:02:59 PM
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>>&vis,int di[], int dj[],int n, int m){
        vis[row][col] = 1;
        for(int i= 0; i<4; i++){
            int r = row+di[i];
            int c = col+dj[i];
            if(r<n&&r>=0&&c<m&&c>=0){
                if(!vis[r][c]&&board[r][c]=='O'){
                    dfs(r,c,board,vis,di,dj,n,m);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int di[] = {-1,0,1,0};
        int dj[] = {0,1,0,-1};
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i = 0; i<col; i++){
            if(!vis[0][i]&&board[0][i]=='O'){
                dfs(0,i,board,vis,di,dj,row,col);
            }
            if(!vis[row-1][i]&&board[row-1][i]=='O'){
                dfs(row-1,i,board,vis,di,dj,row,col);
            }
        }
        for(int i = 0; i<row; i++){
            if(!vis[i][0]&&board[i][0]=='O'){
                dfs(i,0,board,vis,di,dj,row,col);
            }
            if(!vis[i][col-1]&&board[i][col-1]=='O'){
                dfs(i,col-1,board,vis,di,dj,row,col);
            }
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cout << vis[i][j] << " ";
                if(vis[i][j]==0&&board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
            cout << endl;
        }
    }
};