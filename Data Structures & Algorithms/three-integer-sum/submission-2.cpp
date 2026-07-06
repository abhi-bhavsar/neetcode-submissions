class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(),nums.end()) ;
     int n= nums.size() ;
     vector<vector<int>> ans ;
     unordered_map<int,int>mp ;
      for(int i=0;i<nums.size();i++) {mp[nums[i]]=i ;}
      
     for(int i=0;i<nums.size();i++) {
        if(i>0 && nums[i]==nums[i-1]) {continue ;}
        for(int j=i+1; j<nums.size();j++) {
            if(j>i+1 && nums[j]==nums[j-1]) {continue;}
                int target = -(nums[i] + nums[j]) ;
                
                // element exist in array
                if(mp.find(target)!=mp.end() && mp[target]>j) {
                    
                    ans.push_back({nums[i],nums[j],target}) ;
                }
           }
        }
        
     return ans ;  
    }
};
