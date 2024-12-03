class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int a = (coordinate1[0] - 'a' + coordinate1[1] - '1') % 2;
        int b = (coordinate2[0] - 'a' + coordinate2[1] - '1') % 2;
        return a == b;
    }
};