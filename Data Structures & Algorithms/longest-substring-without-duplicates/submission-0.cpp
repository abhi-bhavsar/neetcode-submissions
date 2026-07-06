class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>vec(257,0) ;
        int i = 0 ;
        int j = 0 ;
        int maxcnt = 0 ;
        while(i<s.length()) {
            vec[s[i]]++ ;
            if(vec[s[i]]>1){
                while(j<=i && vec[s[i]]!=1){
                    vec[s[j]]--;
                    j++ ;
                }
                
            }
        maxcnt = max(maxcnt,i-j+1) ;
            i++ ;
        }
        return maxcnt ;
    }
};
