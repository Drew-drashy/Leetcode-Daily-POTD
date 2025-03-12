class MinStack {
public:
    int mini=INT_MAX;
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty()){
            st.push({val,val});
        }
        else{
            int temp=min(val,st.top().second);
            st.push({val,temp});

        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        return st.top().second;
    }
};

