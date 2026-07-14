class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>grid(n) ;
        for(int i=0;i<flights.size();i++) {
            int u = flights[i][0] ;
            int v = flights[i][1] ;
            int w = flights[i][2] ;

            grid[u].push_back({v,w}) ;
        }

        vector<int>dist(n,INT_MAX) ;
        queue<pair<int,pair<int,int>>> pq;
        dist[src] = 0 ;
        pq.push({0,{src,0}}) ;
        while(!pq.empty()) {
            auto it = pq.front() ;
            int stops = it.first ;
            int node = it.second.first ;
            int distance = it.second.second ;
            pq.pop() ;
            if(stops>k) {continue ;}
            for(int i=0;i<grid[node].size();i++) {
                int curr_node = grid[node][i].first ;
                int curr_dist = grid[node][i].second ;

                if(curr_dist + distance < dist[curr_node] && stops<=k) {
                    dist[curr_node] = curr_dist + distance ;
                    pq.push({stops+1,{curr_node,dist[curr_node]}}) ;
                }
            }
        }

        
        return dist[dst]==INT_MAX ? -1 : dist[dst] ;
    }
};
