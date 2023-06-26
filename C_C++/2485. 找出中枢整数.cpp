class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int x = sqrt(t);
        if(x * x != t) {
            return -1;
        } else {
            return x;
        }
    }
};