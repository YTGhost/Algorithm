class Solution {
public:
    int cnts[3];
    bool stoneGameIX(vector<int>& stones) {
        for(auto stone : stones) {
            cnts[stone % 3]++;
        }
        return cnts[0] % 2 == 0 ? cnts[1] != 0 && cnts[2] != 0 : abs(cnts[1] - cnts[2]) > 2;
    }
};