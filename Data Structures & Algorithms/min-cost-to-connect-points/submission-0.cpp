class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // minimum spanning tree + disjkstra's 

        int n = points.size() ;
        vector<vector<pair<int,int>>>grid(n) ;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int u = i  ;
                int v = j  ;

                int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]) ;

                grid[u].push_back({v,cost}) ;
                grid[v].push_back({u,cost}) ;
            }
        }

        // min-heap for dj 
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>>pq ;
        vector<int>visited(n,0) ;
        int dist = 0 ;
        pq.push({0,0}) ;

        while(!pq.empty()) {
            auto it =  pq.top() ;
            int node = it.second ;
            int cost = it.first ; 
            pq.pop() ;
            if(visited[node]) {continue;}
            visited[node] = 1 ;
            dist+=cost ;
            for(int i=0;i<grid[node].size();i++) {
                int curr_node = grid[node][i].first ;
                int curr_dist = grid[node][i].second ;

                if(visited[curr_node]==0) {
                    pq.push({curr_dist,curr_node}) ;
                }
            }
        }
        return dist ;
    }
};
