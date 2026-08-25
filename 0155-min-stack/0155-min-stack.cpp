class MinStack {
public:
    // stack<pair<int,int>>st;
    long long mini=INT_MAX;
    stack<long long>st;
    MinStack() {
        
    }
    
    void push(int value) {

        if(st.empty()){
            mini=value;
            st.push(value);
        }
        else{
            if(mini>value){
                long long newval=2LL*value-mini;
                mini=value;
                st.push(newval);
            }else{
                st.push(value);
            }
        }

        // if(st.empty()){
        //     st.push({value,value});
        // }
        // else{
        //     st.push({value,min(value,st.top().second)});
        // }
    }
    
    void pop() {
        // st.pop();
        if(st.empty()){
            return;
        }
        if(st.top()<mini){
            long long preval=2LL*mini-(st.top());
            mini=preval;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        else if(st.top()<mini){
            return mini;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */