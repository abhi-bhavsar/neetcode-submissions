class Solution {
public:
    int jump(vector<int>& nums) {
        
        int steps = 0 ;
        int maxreach = 0 ;
        int n = nums.size() ;
        if(n==1) {return 0 ;}
        int index = 0  ;
        for(int i=0;i<nums.size();i++) {
            
            maxreach = max(maxreach,i+nums[i]) ;

            if(i==index){
                index = maxreach ;
                steps++ ;
                if(maxreach>=n-1) { break;}
            }

            
            

        }

        return steps ;
    }
};
