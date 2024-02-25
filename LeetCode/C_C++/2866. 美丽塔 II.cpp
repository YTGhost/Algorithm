class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0, sum = 0;
        int n = maxHeights.size();
        stack<int> st;
        st.push(n);
        vector<long long> suf(n + 1);
        for(int i = n - 1; i >= 0; i--) {
            int x = maxHeights[i];
            while(st.size() > 1 && x <= maxHeights[st.top()]) {
                int j = st.top();
                st.pop();
                sum -= (long long)maxHeights[j] * (st.top() - j);
            }
            sum += (long long)x * (st.top() - i);
            suf[i] = sum;
            st.push(i);
        }
        res = sum;
        st = stack<int>();
        st.push(-1);
        long long pre = 0;
        for(int i = 0; i < n; i++) {
            int x = maxHeights[i];
            while(st.size() > 1 && x <= maxHeights[st.top()]) {
                int j = st.top();
                st.pop();
                pre -= (long long)maxHeights[j] * (j - st.top());
            }
            pre += (long long)x * (i - st.top());
            st.push(i);
            res = max(res, (long long)pre + suf[i + 1]);
        }
        return res;
    }
};