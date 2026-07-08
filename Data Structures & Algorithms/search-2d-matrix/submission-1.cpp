class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {return false ;}
        int rows = matrix.size() ;
        int cols = matrix[0].size() ;

        int low =  0 ;
        int high = (rows*cols)-1 ;
        
        while(low<=high) {
            int mid = (low + high) /2 ;
            int midvalue = matrix[mid/cols][mid%cols] ;
            if(midvalue==target) {return true;}
            else if(target>midvalue) {low++ ;}
            else {high--;}
        }
        return false;
    }
};
