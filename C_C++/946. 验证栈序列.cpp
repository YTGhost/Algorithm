class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> data;
        int i = 0;
        for(auto num : pushed)
        {
            data.push(num);
            while(!data.empty() && data.top() == popped[i])
            {
                data.pop();
                i++;
            }
        }
        return data.empty();
    }
};