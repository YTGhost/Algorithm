class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N--);
        int index = 0;
        while(N > 0)
        {
            if(index % 4 == 0) {
                int t = stk.top();
                stk.pop();
                stk.push(t * N);
            } else if(index % 4 == 1) {
                int t = stk.top();
                stk.pop();
                stk.push(t / N);
            } else if(index % 4 == 2) {
                stk.push(N);
            } else {
                stk.push(-N);
            }
            index++;
            N--;
        }
        int sum = 0;
        while(!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};