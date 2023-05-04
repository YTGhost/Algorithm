class Solution {
public:
    int passThePillow(int n, int time) {
        int a = time / (n - 1);
        int b = time % (n - 1);
        int res;
        if(a % 2 == 0) {
            res = 1 + b;
        } else {
            res = n - b;
        }
        return res;
    }
};