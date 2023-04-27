class Solution {
public:
    int getHash(int x, int y) {
        return x * 20001 + y;
    }
    bool isPathCrossing(string path) {
        unordered_set<int> s;
        int x = 0, y = 0;
        s.insert(getHash(x, y));
        for(auto c : path) {
            switch (c) {
                case 'N': y++; break;
                case 'S': y--; break;
                case 'E': x++; break;
                case 'W': x--; break;
            }
            int hashVal = getHash(x, y);
            if(s.find(hashVal) != s.end()) {
                cout << hashVal << endl;
                return true;
            } else {
                s.insert(hashVal);
            }
        }
        return false;
    }
};