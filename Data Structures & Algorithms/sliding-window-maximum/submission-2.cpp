class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       
        deque<int>qu ;
       
        vector<int>vec;
        for(int r = 0 ;r<nums.size();r++) {

            if(!qu.empty() && qu.front()==r-k) {
                qu.pop_front() ;
            }
            
            while(!qu.empty() && nums[r] >nums[qu.back()]) {qu.pop_back();}
            
            qu.push_back(r) ;
            if(r>=k-1) {
                vec.push_back(nums[qu.front()]) ;
             }

        }
        return vec ;
    }
};
