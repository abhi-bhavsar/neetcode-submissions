class disjoint_set{
    vector<int>parent,rank ;
    public : 
    disjoint_set(int n) {
        parent.resize(n,0) ;
        rank.resize(n,0) ;

        for(int i=0;i<n;i++) {
            parent[i] = i ;
        }
    }
        int find_parent(int node) {
            if(node==parent[node]) {
                return parent[node] ;
            }
            return parent[node] = find_parent(parent[node]) ;
        }

        void union_by_rank(int u,int v) {
            int ulp_u = find_parent(u) ;
            int ulp_v = find_parent(v) ;
            if(ulp_u==ulp_v) {return ;}
            if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u ;
             }
            else if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v ;
            }
            else {
                parent[ulp_u] = ulp_v ;
                rank[ulp_v]++ ;
            }
        }
    };
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) {return false ;}
        disjoint_set ds(n) ;
        for(int i=0;i<edges.size();i++) {
            int u = edges[i][0] ;
            int v = edges[i][1] ; 

            if(ds.find_parent(u)==ds.find_parent(v)) {
                return false ;
            }
            else {
                ds.union_by_rank(u,v) ;
            }
       }
       return true ;
    }
};
