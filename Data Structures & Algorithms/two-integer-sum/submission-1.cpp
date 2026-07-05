class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>vec; 
        unordered_map<int,int> mp; 
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]] = i ;
        }
        for(int i=0;i<nums.size();i++) {
            int num = target - nums[i] ;
            if(mp.find(num)!=mp.end() && mp[num]!=i){
                vec.push_back(i) ;
                vec.push_back(mp[num]) ;
                return vec;
            }
        }
        return {} ;
    }
};
