class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = INT_MAX ;
        int profit = 0 ;
     for(int i=0;i<prices.size();i++) {
         price = min(prices[i],price) ;
        profit = max(profit , prices[i]-price) ;
     }
     return profit ;
    }
};
