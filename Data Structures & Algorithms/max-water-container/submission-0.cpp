class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0 ;
        int n = heights.size() ;
        int right  = n-1 ;
        int maxcap = INT_MIN ;
        
        while(left<right) {
            int dist = right-left ;
            int num  = dist * min(heights[right],heights[left]); 
            maxcap = max(num,maxcap) ;
            if(heights[right]>heights[left]){left++ ;}
            else if(heights[right]<heights[left]) {right-- ;}
            else {left++ , right--;}
        }
    return maxcap;
    }
};
