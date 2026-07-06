class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        vector<int>left_height(n) ;
        vector<int>right_height(n) ;
        left_height[0] = height[0] ;
        right_height[n-1] = height[n-1] ;
        // left max height
        for(int i=1;i<n;i++) {
            left_height[i] = max(left_height[i-1],height[i]) ;
        }
        // right max height
        for(int j=n-2;j>=0;j--) {
            right_height[j] = max(right_height[j+1],height[j]) ;
        }
        int sum = 0 ;
        for(int i=0;i<n;i++ ){
            int ht =  min(left_height[i], right_height[i]) - height[i] ;
            sum += ht ;
        }
    return sum ;
    }
};
