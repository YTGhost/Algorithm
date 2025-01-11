class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string n1 = to_string(num1), n2 = to_string(num2), n3 = to_string(num3);
        n1.insert(0, 4 - n1.length(), '0');
        n2.insert(0, 4 - n2.length(), '0');
        n3.insert(0, 4 - n3.length(), '0');
        string res = "";
        for (int i = 0; i < 4; i++) {
            res.push_back('0' + min({n1[i] - '0', n2[i] - '0', n3[i] - '0'}));
        }
        return stoi(res);
    }
};