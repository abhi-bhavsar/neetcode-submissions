class Solution {
public:
    int bfs(queue<pair<int,pair<int,int>>>&qu,vector<vector<int>>&grid,
    vector<vector<int>>&visited) {
         int n = grid.size() ;
        int m = grid[0].size() ;
        int maxi = 0 ;
        vector<int>delrow = {-1,0,1,0} ;
        vector<int>delcol = {0,1,0,-1} ;

        while(!qu.empty()) {
            auto it = qu.front() ;
            qu.pop() ;
            int time = it.first ;
            int x = it.second.first ;
            int y = it.second.second ;
            maxi = max(time,maxi) ;
            for(int i=0;i<4;i++) {
                int row = x + delrow[i] ;
                int col = y + delcol[i] ;

                if(row>=0 && col>=0 && row<n && col<m && !visited[row][col] 
                && grid[row][col]==1 ) {
                    visited[row][col]  = 1 ;
                    qu.push({time+1,{row,col}}) ;
                }
            }
        }
        return maxi ;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>>visited(n,vector<int>(m,0)) ;

        queue<pair<int,pair<int,int>>> qu ;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2 && !visited[i][j]) {
                    visited[i][j] = 1  ;
                    qu.push({0,{i,j}}) ;
                } 
            }
        } 
        int ans = bfs(qu,grid,visited);
          for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    return -1 ;
                } 
            }
        } 
        return ans   ;
    }
};
