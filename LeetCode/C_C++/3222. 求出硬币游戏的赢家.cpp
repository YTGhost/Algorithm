class Solution {
public:
    string losingPlayer(int x, int y) {
        int t = min(x, y / 4);
        return t % 2 == 0 ? "Bob" : "Alice";
    }
};

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