class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for (auto command : commands) {
            if (command == "UP") {
                i--;
            } else if (command == "RIGHT") {
                j++;
            } else if (command == "DOWN") {
                i++;
            } else {
                j--;
            }
        }
        return i * n + j;
    }
};