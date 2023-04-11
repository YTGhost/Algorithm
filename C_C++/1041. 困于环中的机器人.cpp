class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> direc{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, direcIdx = 0;
        for(auto c : instructions) {
            if(c == 'G') {
                x += direc[direcIdx][0];
                y += direc[direcIdx][1];
            } else if(c == 'L') {
                direcIdx += 3;
                direcIdx %= 4;
            } else {
                direcIdx++;
                direcIdx %= 4;
            }
        }
        return (x == 0 && y == 0) || direcIdx != 0;
    }
};