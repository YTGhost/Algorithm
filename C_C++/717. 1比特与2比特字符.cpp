class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0, n = bits.size();
        while(idx < n - 1) {
            idx += bits[idx] + 1;
        }
        return idx == n - 1;
    }
};