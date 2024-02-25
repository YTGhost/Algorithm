class Solution {
public:
    int passThePillow(int n, int time) {
        int t = (n - 1) * 2;
        time = time % t;
        int res;
        if(time > n - 1) {
            res = n - (time - n + 1);
        } else {
            res = time + 1;
        }
        return res;
    }
};

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