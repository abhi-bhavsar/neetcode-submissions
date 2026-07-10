class KthLargest {
    priority_queue<int, std::vector<int>, std::greater<int>> pq;    vector<int>num ;
    int k  ;
public:
    KthLargest(int k, vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]) ;
            if(pq.size()>k) {pq.pop();}
        }
        this->k = k;
    }
    
    int add(int val) {
       pq.push(val) ;
       if(pq.size()>k){pq.pop();}
       return pq.top() ;
    }
};
