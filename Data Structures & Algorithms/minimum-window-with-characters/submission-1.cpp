class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(257,0) ;
        for(int i=0;i<t.length();i++) {
            hash[t[i]]++ ;
        }

        int l = 0 , r = 0;
        int cnt = 0 ;
        int start_index= -1 ;
        int min_length = INT_MAX ;
        while(r<s.length()) {
            if(hash[s[r]]>0) {
                cnt++ ;
            }
            hash[s[r]]-- ;
            while(cnt==t.length()) {
                
                if(r-l+1<min_length) {
                start_index = l ;
                min_length = (r-l+1) ;
                }
                hash[s[l]]++ ;
                if(hash[s[l]]>0) {cnt--;}
                l++ ;
            }
            r = r+1;
        }
        return start_index==-1 ? "" :  s.substr(start_index,min_length) ;
    }
};
