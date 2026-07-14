class Solution {
public:
    int bin_search(vector<int>&nums) {
        int n = nums.size() ;

        int low = 0, high = n-1 ;
        while(low<=high) {
            int mid = low + (high-low) /2;
            if(mid+1<=nums[mid]) {low = mid+1 ;}
            else {high = mid - 1 ;}
        }
        return nums[low] ;
    }
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;

        return bin_search(nums) ;
    }
};
