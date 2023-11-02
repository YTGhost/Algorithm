class Solution {
public:
    int countPoints(string rings) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < rings.size(); i+=2) {
            int t = m[rings[i + 1] - '0'];
            if(rings[i] == 'R') {
                t |= (1 << 2);
            } else if(rings[i] == 'G') {
                t |= (1 << 1);
            } else {
                t |= 1;
            }
            m[rings[i + 1] - '0'] = t;
        }
        for(auto& [_, v] : m) {
            if(v == 7) {
                res++;
            }
        }
        return res;
    }
};