class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int idx1 = num1.find('+'), idx2 = num1.find('i');
        int a = stoi(num1.substr(0, idx1)), b = stoi(num1.substr(idx1 + 1, idx2));
        idx1 = num2.find('+'), idx2 = num2.find('i');
        int c = stoi(num2.substr(0, idx1)), d = stoi(num2.substr(idx1 + 1, idx2));
        int sum1 = a * c + b * d * -1;
        int sum2 = a * d + b * c;
        string res = to_string(sum1) + "+" + to_string(sum2) + "i";
        return res;
    }
};