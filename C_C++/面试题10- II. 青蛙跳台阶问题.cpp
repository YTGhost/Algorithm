class Solution {
public:
    int numWays(int n) {
        int a = 0, b = 1, c = 1;
        for(int i = 1; i < n; i++)
        {
            a = b;
            b = c;
            c = (a + b) % 1000000007;
        }
        return c;
    }
};

class Solution {
public:
    int numWays(int n) {
        long a = 0, b = 0, c = 1;
        for(int i = 0; i < n; i++)
        {
            a = b;
            b = c;
            c = 0;
            c += b;
            if(i == 0) continue;
            c += a;
            c %= 1000000007;
        }
        return c;
    }
};