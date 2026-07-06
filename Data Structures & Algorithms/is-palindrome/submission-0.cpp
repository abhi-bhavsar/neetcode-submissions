class Solution {
public:
    bool isPalindrome(string s) {
     int n = s.length() ;
     int i = 0;
     int j = s.length()-1 ;
    while(i<j) {

       if(!isalnum(s[i])) {i++ ;}
       if(!isalnum(s[j])) {j-- ;}

       if(isalnum(s[i]) && isalnum(s[j])) {
        if(tolower(s[i])!=tolower(s[j]) ) {return false;}
        i++ ,j--;
       }  
    }
    return true ;
    }
};
