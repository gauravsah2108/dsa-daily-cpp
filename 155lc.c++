#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;       // main stack
    stack<int> minSt;    // keeps track of minimums

public:
    MinStack() { }

    void push(int val) {
        st.push(val);
        // If min stack is empty or val <= current min, push to min stack too
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    
    void pop() {
        if (st.empty()) return;
        int topVal = st.top();
        st.pop();
        // If the popped element is the current minimum, pop from min stack as well
        if (!minSt.empty() && topVal == minSt.top())
            minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl;    // 0
    cout << minStack.getMin() << endl; // -2
    return 0;
}
