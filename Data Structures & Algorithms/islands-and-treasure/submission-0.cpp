class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>&qu){
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<int>delrow = {-1,0,1,0} ;
        vector<int>delcol = {0,1,0,-1} ;
       

        while(!qu.empty()) {
            int x = qu.front().first ;
            int y = qu.front().second ;
            qu.pop() ;

            for(int k=0;k<4;k++) {
                int row = delrow[k] + x ;
                int col = delcol[k] + y ;
                if(row>=0 && col>=0 && row<n && col<m 
                && grid[row][col]==INT_MAX ) {
                        grid[row][col] = grid[x][y] + 1 ;
                        qu.push({row,col}) ;
                    }
                }
            }
        }
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<int,int>>qu ;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==0 ){
                    qu.push({i,j}) ;
                }
            }
        }   
        bfs(grid,qu);
    }
};
