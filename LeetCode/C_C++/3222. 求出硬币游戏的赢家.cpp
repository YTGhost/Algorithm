class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag = true;
        while (x >= 1 && y >= 4) {
            flag = !flag;
            x--;
            y -= 4;
        }
        return flag ? "Bob" : "Alice";
    }
};