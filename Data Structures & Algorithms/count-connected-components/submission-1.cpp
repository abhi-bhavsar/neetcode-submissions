class Solution {
public:
    void bfs(int i,vector<vector<int>>&grid,vector<int>&visited) {
        visited[i] = 1 ;
        queue<int>qu ;
        qu.push(i) ;

        while(!qu.empty()) {
            int node = qu.front() ;
            qu.pop() ;
            for(int j=0;j<grid[node].size();j++) {
                int curr_node = grid[node][j] ;
                if(!visited[curr_node]) {
                visited[curr_node] = 1 ;
                qu.push(curr_node) ; }
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0) ;
        vector<vector<int>> grid(n);
        // create a grid ;
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            grid[u].push_back(v) ;
            grid[v].push_back(u) ;
        }

        int cnt = 0 ;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                cnt++ ;
                bfs(i,grid,visited) ;
            }
        }
        return cnt ;
    }
};
