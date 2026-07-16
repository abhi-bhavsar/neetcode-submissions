class disjoint_set {
    vector<int>rank ;
    vector<int>parent ; 
    public : 
    disjoint_set(int n) {
        rank.resize(n+1,0) ;
        parent.resize(n+1,0) ;
        for(int i=0;i<=n;i++) {
            parent[i] = i ;
        }
    }

    int find_parent(int node) {
        if(node==parent[node]) {
            return parent[node] ;
        }
        return parent[node] = find_parent(parent[node]) ;
    }

    bool union_by_rank(int u,int v) {
        int ulp_u = find_parent(u) ;
        int ulp_v = find_parent(v) ;

        if(ulp_v==ulp_u) {return true ; }
        
        if(rank[ulp_v]>rank[ulp_u]) {
            parent[ulp_u] = ulp_v ;
         }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u ; 
        }
        else {
            parent[ulp_v] = ulp_u ; 
            rank[ulp_u]++ ;
        }
        return false ;
    } 
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size() ;
        disjoint_set ds(n) ;
        vector<int>ans ;
        for(int i=0;i<edges.size();i++ ){
            if(ds.union_by_rank(edges[i][0],edges[i][1])) {
                ans.push_back(edges[i][0]) ;
                ans.push_back(edges[i][1]) ;
            }
        }

        return ans ;
    }
};
