// Last updated: 1/11/2026, 12:59:44 PM
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool check(int i, int j, int n, int m){
        if(i >= 0 && i < n && j >= 0 && j < m) return true;
        return false;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> mat(m,vector<char>(n,'.'));
        queue<pair<int,int>> q;
        for(auto &it: walls){
            int x = it[0], y = it[1];
            mat[x][y] = 'W';
        }
        for(auto &it: guards){
            int x = it[0], y = it[1];
            mat[x][y] = 'G';
            q.push({x,y});
        }
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                while(check(nr, nc, m, n) && mat[nr][nc] != 'W' && mat[nr][nc] != 'G'){
                    mat[nr][nc] = 'P';
                    nr += dx[i];
                    nc += dy[i];
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cout << mat[i][j] << ' ';
                if(mat[i][j] == '.'){
                    cnt++;
                }
            }
            cout << endl;
        }
        return cnt;
    }
};