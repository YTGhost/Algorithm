class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a', b = coordinates[1] - '1';
        return !(a % 2 == b % 2);
    }
};

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int a = coordinates[0] - 'a';
        int b = coordinates[1] - '1';
        if(a % 2 == 0) {
            return b % 2 != 0;
        } else {
            return b % 2 == 0;
        }
    }
};