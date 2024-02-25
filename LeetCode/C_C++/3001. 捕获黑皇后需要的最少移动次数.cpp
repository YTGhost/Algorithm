class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a == e) {
            if(a != c) {
                return 1;
            } else if(b < f && d > b && d < f) {
                return 2;
            } else if(b > f && d > f && d < b) {
                return 2;
            } else {
                return 1;
            }
        }
        if(b == f) {
            if(b != d) {
                return 1;
            } else if(a < e && c > a && c < e) {
                return 2;
            } else if(a > e && c > e && c < a) {
                return 2;
            } else {
                return 1;
            }
        }
        double t = 1.0 * (c - e) / (d - f);
        if(t == -1.0 || t == 1.0) {
            if(1.0 * (a - e) / (b - f) == t) {
                if(c > e) {
                    if(a > e && a < c) {
                        return 2;
                    }
                } else {
                    if(a > c && a < e) {
                        return 2;
                    }
                }
            }
            return 1;
        }
        return 2;
    }
};