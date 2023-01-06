class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for(int i = 1; i <= num; i++) {
            int sum = 0, t = i;
            while(t) {
                sum += t % 10;
                t /= 10;
            }
            res += sum % 2 == 0;
        }
        return res;
    }
};