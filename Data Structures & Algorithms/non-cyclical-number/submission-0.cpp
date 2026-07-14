class Solution {
public: 
    int opr(int n) {
        int sum = 0 ;
        while(n>0) {
            int dig = n%10 ;
            sum += (dig * dig) ;
            n /= 10 ;
        }
        return sum ; 
    }
    bool isHappy(int n) {
        
        unordered_map<int,int> mp ;
        while(n!=1) {
            int happy = opr(n) ;
            if(mp.find(happy)==mp.end()) {
                mp[happy] = 1  ;
            }
            else {return false ;}
            n = happy ;
        }

        return true ;
    }
};
