class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){return 0;}

        unordered_set<int> mp(nums.begin(), nums.end());
        int maxcnt = 0;
        for(int i=0;i<nums.size();i++) {
            int cnt = 0 ;
            if(mp.find(nums[i]-1)==mp.end()) {
                int x = nums[i] ;
                while(mp.find(x)!=mp.end()){
                    x++ ;
                    cnt++ ;
                }
            maxcnt = max(cnt , maxcnt) ;
            }
        }       
        return maxcnt==INT_MIN ? 0 : maxcnt ;
    }
};
