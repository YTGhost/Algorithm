class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int v1 = 1;
        for(int i = 0; i < 20; i++) {
            int v2 = 1;
            for(int j = 0; j < 20; j++) {
                int res = v1 + v2;
                if(res <= bound) {
                    s.insert(res);
                } else {
                    break;
                }
                v2 *= y;
            }
            if(v1 > bound) {
                break;
            }
            v1 *= x;
        }
        return vector<int>{s.begin(), s.end()};
    }
};