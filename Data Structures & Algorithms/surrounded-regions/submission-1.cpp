class Solution {
public:
    void bfs(vector<vector<char>>&board,vector<vector<int>>&visited,int i,int j) {
        visited[i][j] = 1 ;
        queue<pair<int,int>> qu;
        qu.push({i,j}) ;
         int n = board.size() ;
        int m = board[0].size() ; 
        vector<int>delrow = {-1,0,1,0} ;
        vector<int>delcol = {0,1,0,-1} ;

        while(!qu.empty()) {
            int x = qu.front().first ;
            int y = qu.front().second ;
            qu.pop() ;

            for(int k=0;k<4;k++) {
                int row = delrow[k] + x ;
                int col = delcol[k] + y ;

                if(row>=0 && col>=0 && col<m && row<n && !visited[row][col] 
                && board[row][col]=='O') {
                    visited[row][col] = 1 ;
                    qu.push({row,col}) ;
                } 
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        int m = board[0].size() ;
        vector<vector<int>>visited(n,vector<int>(m,0)) ;

        // boundary traversal to fill '0; 
        // top
        for(int i=0;i<m;i++) {
            if(board[0][i]=='O' && !visited[0][i]) {
                bfs(board,visited,0,i) ;
            }
        }
        // left 
         for(int i=0;i<n;i++) {
            if(board[i][0]=='O' &&  !visited[i][0]) {
                bfs(board,visited,i,0) ;
            }
        }
        // right 
         for(int i=0;i<n;i++) {
            if(board[i][m-1]=='O' && !visited[i][m-1]) {
                bfs(board,visited,i,m-1) ;
            }
        }
        // bottom
         for(int i=0;i<m;i++) {
            if(board[n-1][i]=='O' && !visited[n-1][i]) {
                bfs(board,visited,n-1,i) ;
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && board[i][j]=='O') {
                    board[i][j] = 'X' ;
                }
            }
        }
     }
};
