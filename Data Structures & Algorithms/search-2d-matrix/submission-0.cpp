class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int low =  0 ;
        int high = m-1 ;
        
        while(low<n && high>=0) {
            int start = matrix[low][high] ;
            if(start==target) {return true ;}
            else if(target>start) {low++ ;}
            else {high--;}
        }
        return false;
    }
};
