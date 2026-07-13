class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& c, vector<int>& newInterval) {
    int n = c.size() ;

     vector<vector<int>>ans ; 
     int lb = newInterval[0] ;
     int ub = newInterval[1] ;
    int i =0 ;
     while(i<n && c[i][1]<lb) {
        ans.push_back(c[i]) ; i++;
     }

     while(i<n && ub>=c[i][0]){
        lb = min(lb,c[i][0]) ;
        ub = max(ub,c[i][1]) ;
        i++; 
     }
     ans.push_back({lb,ub}) ;

    while(i<n) {
        ans.push_back(c[i]) ;
        i++ ;
    }

    return ans ;
    }
    
};
