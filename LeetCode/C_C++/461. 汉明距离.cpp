class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x && y) {
            int a = x & 1, b = y & 1;
            if(a != b) res++;
            x >>= 1;
            y >>= 1;
        }
        while(x) {
            if(x&1) res++;
            x >>= 1;
        } 
        while(y) {
            if(y&1) res++;
            y >>= 1;
        } 
        return res;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        while(x && y)
        {
            int t1 = x&1;
            int t2 = y&1;
            if(t1 != t2) dist++;
            x >>= 1;
            y >>= 1;
        }
        while(x) {
            if(x&1) dist++;
            x >>= 1;
        } 
        while(y) {
            if(y&1) dist++;
            y >>= 1;
        } 
        return dist;
    }
};