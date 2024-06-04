#include <iostream>
#include "Stack.cpp"

class MyQueue {

    stack<int> first;
public:
    void push(int x) {
        first.push(x);
    }

    // do re-arrangement if push operations are smaller
    int pop() {
        stack<int> second;
        while(!first.empty()){
            int x = first.top();
            first.pop();
            second.push(x);
        }
        int x = second.top();
        second.pop();
        while(!second.empty()){
            int x = second.top();
            second.pop();
            first.push(x);
        }
        return x;
    }

    int peek() {
        stack<int> second;
        while(!first.empty()){
            int x = first.top();
            first.pop();
            second.push(x);
        }
        int x = second.top();
        while(!second.empty()){
            int x = second.top();
            second.pop();
            first.push(x);
        }
        return x;
    }

    bool empty() {
        return first.empty();
    }
};