class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> q(n);
        q[0] = 1;
        int index = 1;
        for(int i = 0, j = 0, k = 0; index < n; index++)
        {
            int a = q[i] * 2, b = q[j] * 3, c = q[k] * 5;
            int t = min(a, min(b, c));
            q[index] = t;
            if(t == a) i++;
            if(t == b) j++;
            if(t == c) k++;
        }
        return q[n-1];
    }
};