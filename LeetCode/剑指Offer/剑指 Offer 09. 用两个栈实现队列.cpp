// 剑指打卡
class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int ans;
        if(!s2.empty())
        {
            ans = s2.top();
            s2.pop();
        }else{
            while(!s1.empty())
            {
                ans = s1.top();
                s1.pop();
                s2.push(ans);
            }
            if(s2.empty()) ans = -1;
            else{
                ans = s2.top();
                s2.pop();
            }
        }
        return ans;
    }
};

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;

    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int t;
        if(!s2.empty()){
            int x = s2.top();
            s2.pop();
            t = x;
        }else{
            t = -1;
            if(s1.empty()) return t;
            else{
                while(!s1.empty())
                {
                    int x = s1.top();
                    s2.push(x);
                    s1.pop();
                }
                t = s2.top();
                s2.pop();
            }
        }
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */