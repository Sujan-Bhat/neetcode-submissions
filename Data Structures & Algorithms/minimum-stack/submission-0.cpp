class MinStack {
public:
    stack<int> s;
    stack<int> minValueStack;

    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(minValueStack.size() == 0){
            minValueStack.push(value);
        } else{
            if(minValueStack.top() > value){
                minValueStack.push(value);
            } else{
                minValueStack.push(minValueStack.top());
            }
        }
    }
    
    void pop() {
        s.pop();
        minValueStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minValueStack.top();
    }
};
