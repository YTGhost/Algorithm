class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int t = x;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        return x % sum == 0 ? sum : -1;
    }
};