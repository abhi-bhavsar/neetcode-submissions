class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp ; 
        int cnt = INT_MIN ;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++ ;
        }
        vector<vector<int>> vec(10001) ;
        for(auto it : mp) {
            int num = it.first ; // number
            int index = it.second  ; // frequency
            vec[index].push_back(num) ;
        }
        vector<int>ans ;
        for(int i=10001-1;i>=0;i--) {
            if(k>0) {
            for(int j=vec[i].size()-1;j>=0;j--) {
            ans.push_back(vec[i][j]) ;
            k-- ;
            if(k==0){return ans ;} 
            } }
        }
    return ans;
    }
};
