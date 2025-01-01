class Solution {
public:
    string toBinary(int num) {
        string binary = "";
        while (num) {
            binary += '0' + (num & 1);
            num >>= 1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};