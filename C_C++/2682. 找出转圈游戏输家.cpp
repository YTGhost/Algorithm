class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> hash(n, 0);
        int idx = 0, cnt = 1;
        while(hash[idx] == 0) {
            hash[idx] = 1;
            idx = (idx + cnt * k) % n;
            cnt++;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(hash[i] == 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};