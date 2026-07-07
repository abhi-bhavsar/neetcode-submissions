class Solution {
public:

    void bfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j){
        visited[i][j] = 1 ;
        queue<pair<int,int>> qu ;
        qu.push({i,j}) ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<int>delrow = {-1,0,1,0} ;
        vector<int>delcol = {0,1,0,-1} ;
        while(!qu.empty()) {
            int x = qu.front().first ;
            int y = qu.front().second ;
            qu.pop() ;
            for(int k=0;k<4;k++) {
                int row = x + delrow[k] ;
                int col = y + delcol[k] ;

                if(row>=0 && col>=0 && row<n && col<m 
                && grid[row][col]-'0'==1 && !visited[row][col]){
                    visited[row][col] = 1 ;
                    qu.push({row,col}) ;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> visited(n,vector<int>(m,0)) ;
        int cnt = 0 ;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]-'0'==1 && !visited[i][j]) {
                    cnt++ ;
                    bfs(grid,visited,i,j) ;
                }
            }
        }
        return cnt ;
    }
};
