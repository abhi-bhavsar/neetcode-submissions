class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     stack<int>st ;
     int n = temperatures.size() ;  
     vector<int>vec(n,0) ;
     for(int i=n-1;i>=0;i--) {
        int curr = temperatures[i] ;
        while(!st.empty() && temperatures[st.top()] <= curr) {
            st.pop() ;
        }
        vec[i]= st.empty() ? i : st.top() ;
        st.push(i) ;
     } 
    for(int i=0;i<n;i++) { temperatures[i] = vec[i]-i ;}
    
      return temperatures;
    }
   
};
