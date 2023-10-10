class MyStack {
public:
    int sz;
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        sz=0;
    }
    
    void push(int x) {
        q1.push(x);
        sz++;
    }
    
    int pop() {
        while(q1.size()!=1){
            int t=q1.front();
            q2.push(t);
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        while(!q2.empty()){
            int t=q2.front();
            q1.push(t);
            q2.pop();
        }
        sz--;
        return ans;
    }
    
    int top() {
        while(q1.size()!=1){
            int t=q1.front();
            q2.push(t);
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        while(!q2.empty()){
            int t=q2.front();
            q1.push(t);
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return sz==0;
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