class MinStack {
    stack<long long> st; 
    long long min_ele; 
    
public:
    MinStack() {
        min_ele = LLONG_MIN; // Update to long long min
    }
    
    void push(int val) {
        if(st.empty()) {
            min_ele = val;
            st.push(val);
        }
        else if(val < min_ele) {
            // Use 2LL to ensure the multiplication happens as a long long
            st.push(2LL * val - min_ele); 
            min_ele = val;
        }
        else {
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) { return; }
        
        long long top = st.top(); // Store top as long long
        st.pop();
        
        if(top < min_ele) {
            min_ele = 2LL * min_ele - top; 
        }
    }
    
    int top() {
        if(st.top() < min_ele) {
            return min_ele;
        }
        return st.top(); 
    }
    
    int getMin() {
        return min_ele;
    }
};