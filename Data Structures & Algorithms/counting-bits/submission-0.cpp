class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0) ;

        for(int i=1;i<=n;i++) {
            int num = i ;
            int cnt = 0 ;
            while(num>0) {
                if(num&1){cnt++ ;}
                num/=2 ;
            }
            ans[i] = cnt ;
        }
        return ans;
    }
};
