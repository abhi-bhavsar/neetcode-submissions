class Solution {
public:

    void get_subsets(int index ,vector<vector<int>>&ans,vector<int>&ds,
    vector<int>&nums,int n) {
        if(index==n){
            ans.push_back(ds) ;
            return ;
        }

        ds.push_back(nums[index]) ;
        get_subsets(index+1, ans, ds, nums, n) ;
        ds.pop_back() ;
        get_subsets(index+1, ans, ds, nums, n) ;
    }
     vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans ;
       int index = 0 ;
       vector<int>ds ;
       int n = nums.size() ;
       get_subsets(index,ans,ds,nums,n) ;
        return ans ;
    }
};
