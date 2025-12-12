class MyStack {
private:
    queue<int> que1;
    queue<int> que2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int>& mainQ = que1.empty() ? que2 : que1;
        queue<int>& sideQ = que1.empty() ? que1 : que2;

        while (!mainQ.empty()){
            int front = mainQ.front();
            sideQ.push(front);
            mainQ.pop();
        }

        mainQ.push(x);

        while (!sideQ.empty()){
            int front = sideQ.front();
            mainQ.push(front);
            sideQ.pop();
        }
    }
    
    int pop() {
        queue<int>& mainQ = que1.empty() ? que2 : que1;

        if (mainQ.empty()) return -1;

        int ret = mainQ.front();
        mainQ.pop();
        return ret;
    }
    
    int top() {
        queue<int>& mainQ = que1.empty() ? que2 : que1;
        queue<int>& sideQ = que1.empty() ? que1 : que2;

        return mainQ.front();
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */