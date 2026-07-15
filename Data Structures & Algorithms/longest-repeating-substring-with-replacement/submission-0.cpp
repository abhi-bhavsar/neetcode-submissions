class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>vec(26,0) ;
        int l = 0 , r = 0 ;
        int maxf = 0 ;
        int maxcnt = 0 ;
        while(r<s.length()) {   
            vec[s[r]-'A']++ ;
            maxf = max(maxf,vec[s[r]-'A']) ;
            while((r-l+1)-maxf>k){
                vec[s[l]-'A']-- ;
                l++ ;
            }
            maxcnt = max(maxcnt , r-l+1) ;        
            r++ ;
        }

        return maxcnt ;
    }
};
