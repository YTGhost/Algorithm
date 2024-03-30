class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size(), cnt = 1;
        for(int i = 0; i < n;) {
            if (cnt == 0) {
                return false;
            } else if (preorder[i] == ',') {
                i++;
                continue;
            } else if (preorder[i] == '#') {
                i++;
                cnt--;
            } else {
                while(i < n && preorder[i] != ',') {
                    i++;
                }
                cnt++;
            }
        }
        return cnt == 0;
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> stk;
        int n = preorder.length();
        int i = 0;
        stk.push(1);
        while(i < n)
        {
            if(stk.empty()) return false;
            if(preorder[i] == ',') {
                i++;
            } else if(preorder[i] == '#') {
                stk.top() -= 1;
                if(stk.top() == 0) stk.pop();
                i++;
            } else {
                while(i < n && preorder[i] != ',') i++;
                stk.top() -= 1;
                if(stk.top() == 0) stk.pop();
                stk.push(2);
            }
        }
        return stk.empty(); 
    }
};