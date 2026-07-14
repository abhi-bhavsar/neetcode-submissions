class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans; 
        int n = digits.size() ;
        digits[n-1]++ ;
        int carry = 0 ;
        for(int i=n-1;i>=0;i--) {
            int sum = digits[i] + carry;
            int num = (sum)%10  ;
            carry = sum/10 ;
            ans.push_back(num ) ;
        }
        if(carry) {ans.push_back(carry);}
        reverse(ans.begin(),ans.end()) ;
        return ans ;
    }
};
