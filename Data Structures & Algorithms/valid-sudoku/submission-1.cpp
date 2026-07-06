class Solution {
public:

    bool check_cell(vector<vector<char>>&board,int n,int m) {

        
        vector<int> v(10, 0);
        for(int i = n ;i<n+3;i++) {    
            for(int j=m;j<m+3;j++) {
                if (board[i][j] == '.') { 
                continue; 
            }
                 int x = board[i][j]-'0' ;
                v[x]++ ;
                if(v[x]>1){return false ;}
            }
        }
        return true ;
    }
    bool check_col(vector<vector<char>>& board) {
        
        int n = board.size();
        for(int i=0;i<n;i++) {
            vector<int>v(10,0) ;
            for(int j=0;j<board[i].size();j++) {
                if (board[j][i] == '.') { 
                continue; 
            }
                int x = board[j][i]-'0' ;
                v[x]++ ;
                if(v[x]>1){return false ;}
            }
        }
        return true ;
    }
    bool check_row(vector<vector<char>>& board) {
    
    
        int n = board.size();
        for(int i=0;i<n;i++) {
             vector<int>v(10,0) ;
            for(int j=0;j<board[i].size();j++) {
                if (board[i][j] == '.') { 
                continue; 
            }
                int x = board[i][j]-'0' ;
                v[x]++ ;
                if(v[x]>1){return false ;}
            }
        }
        return true ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

    if (!check_row(board)) return false;
    if (!check_col(board)) return false;
    
        for(int i=0;i<7;i+=3) {
            for(int j=0;j<7;j+=3) {
                if(!check_cell(board,i,j)){return false ;}
            }
        }
    return true ;
    }
};
