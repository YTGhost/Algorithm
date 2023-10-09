class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        int a = 0, b = 0, n = str.size();
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                a = a * 10 + str[i] - '0';
            } else {
                b = b * 10 + str[i] - '0';
            }
        }
        return a + b;
    }
};