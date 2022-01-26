class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> m;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        m[x][y]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        auto rows = m[x];
        for(auto row : rows) {
            int ny = row.first, cnt = row.second;
            if(y == ny) continue;
            int len = y - ny;
            vector<int> temp{x - len, x + len};
            for(auto item : temp) {
                auto t = m[item];
                res += cnt * t[y] * t[ny];
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */