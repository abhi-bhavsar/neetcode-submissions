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
         while(index+1<n && nums[index+1]==nums[index]) {
            index++ ;
        }
        get_subsets(index+1, ans, ds, nums, n) ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end()) ;
    vector<vector<int>> ans ;
    vector<vector<int>> vec  ;
    vector<int>ds ;

    int index = 0 ;
    int n = nums.size() ;  
  
    get_subsets(index,ans,ds,nums,n) ;
    return ans ;
    
    }
};
