class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        priority_queue<int> pq ;

        for(int i=0;i<nums.size();i++) {
            pq.push({nums[i]}) ;
        } 
        int num =  0;
        while(k!=0) {
            num = pq.top() ;
            pq.pop() ;
            k-- ;
        }
        return num ;
    }
};
