class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            int minval;
            if(val<st.top().second){
                minval = val;
            }
            else minval = st.top().second;
            st.push({val, minval});
        }
    }
    
    void pop() {
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        if(!st.empty())
            return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(!st.empty())
            return st.top().second;
        return -1;
    }
};
