class Solution {
public:
    void bfs(vector<vector<int>>&heights,vector<vector<int>>&visited,int i,int j) {
        visited[i][j] = 1 ;
        queue<pair<int,int>> qu ;
        qu.push({i,j}) ;
         int n = heights.size() ;
        int m = heights[0].size() ;

        vector<int>delrow = {-1,0,1,0} ;
        vector<int>delcol = {0,1,0,-1} ;

        while(!qu.empty()) {
            int x = qu.front().first; 
            int y = qu.front().second ;
            qu.pop() ;

            for(int k=0;k<4;k++) {
                int row = delrow[k] + x ;
                int col = delcol[k] + y ;

                if(row>=0 && col>=0 && col<m && row<n && !visited[row][col] &&
                heights[row][col]>=heights[x][y] 
                ) {
                    visited[row][col] = 1 ;
                    qu.push({row,col}) ;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = heights.size() ;
        int m = heights[0].size() ;

        vector<vector<int>> visited_pacific(n,vector<int>(m,0)) ;
        vector<vector<int>> visited_atlantic(n,vector<int>(m,0))  ;

        // top left --pacific
        for(int i=0;i<m;i++) {
            if(!visited_pacific[0][i]){
                bfs(heights,visited_pacific,0,i) ;
            }
        }

        for(int i=0;i<n;i++) {
            if(!visited_pacific[i][0]) {
                bfs(heights,visited_pacific,i,0) ;
            }
        }
        // botton right -- atlantic
        for(int i=0;i<n;i++) {
            if(!visited_atlantic[i][m-1]) {
                bfs(heights,visited_atlantic,i,m-1) ;
            }
        }

        for(int i=0;i<m;i++) {
         if(!visited_atlantic[n-1][i]) {
                bfs(heights,visited_atlantic,n-1,i) ;
            }   
        }


        vector<vector<int>> ans ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(visited_atlantic[i][j] && visited_pacific[i][j]) {
                    ans.push_back({i,j}) ;
                }
            }
        }
    return ans ;
    }
};
