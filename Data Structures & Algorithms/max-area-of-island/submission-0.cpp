class Solution {
public:
    int bfs(vector<vector<int>>&grid ,vector<vector<int>>&visited,int i,int j,int cnt){
        visited[i][j] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<int,int>> qu ;
        qu.push({i,j});
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
            && !visited[row][col] && grid[row][col]==1 ) {
                cnt++ ;
                visited[row][col] = 1 ;
                qu.push({row,col}) ; 
            }}
        }
        return cnt ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>>visited(n,vector<int>(m,0)) ;
        int maxcnt = 0 ;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    int cnt=1 ;
                    maxcnt = max(maxcnt,bfs(grid,visited,i,j,cnt)) ; 
                }
            }
        }

        return maxcnt ;
    }
};
