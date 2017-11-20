class MyQueue {
public:
    /** Initialize your data structure here. */
    /**
        两个栈A, B实现队列
        如果数x进队的话,将x压入栈B中；
        如果出队或者找队顶元素的话，找A.top(), 
        如果栈A为空，就将栈B中的元素一个个弹出然后压入栈A中，这时候A.top()就是队顶的元素
    **/
    stack<int> A;  // delete from A
    stack<int> B; // push into B

    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        B.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = peek();
        A.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        int tmp;
        if(!A.empty()) tmp = A.top();
        else{
            while(!B.empty()){
                int b = B.top();  A.push(b);
                B.pop();
            }
            tmp = A.top();
        }
        return tmp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       return (A.empty() && B.empty()); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */