class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>vec(27,0) ;

        for(int i=0;i<s1.length();i++) {
            vec[s1[i]-'a']++ ; 
        }

        int i=0 ,j = 0 ;
        int cnt = 0 ;

        while(j<s2.length()) {
            if(vec[s2[j]-'a']>0){cnt++ ;}
            vec[s2[j]-'a']-- ;
            if(j-i+1==s1.length()) {
                if(cnt==s1.length()) {
                    return true ; 
                }
                vec[s2[i]-'a']++ ;
                if(vec[s2[i]-'a']>0) {cnt-- ;}
                i++ ;
            }
            j++ ;
        }

        return false ;
    }
};
