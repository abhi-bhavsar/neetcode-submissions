class Solution {
public:
    int total_eating(vector<int>&piles, int mid) {
        int ans = 0 ;
        for(int i=0;i<piles.size();i++) {
            ans += ceil((double)piles[i]/mid) ;
        }
        return  ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end()) ;
        // int mini = *min_element(piles.begin(),piles.end()) ;

        int low = 1 ,high = maxi ;

        while(low<=high) {
            int mid = (low + high)/2 ;
            int ans = total_eating(piles,mid) ;

            if(ans<=h) {high = mid-1 ;}
            else {low = mid + 1 ;}
        } 
        return low ;
    }
};
