class MyQueue {
private:
    stack<int> mainStack;
    stack<int> subStack;

public:
    MyQueue() {}
    
    void push(int x) {
        while (!mainStack.empty()) {
            int val = mainStack.top();
            subStack.push(val);
            mainStack.pop();
        }

        mainStack.push(x);

        while (!subStack.empty()) {
            int val = subStack.top();
            mainStack.push(val);
            subStack.pop();
        }
    }
    
    int pop() {
        int val = mainStack.top();
        mainStack.pop();
        return val;
    }
    
    int peek() {
        return mainStack.top();
    }
    
    bool empty() {
        return mainStack.empty() && subStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */