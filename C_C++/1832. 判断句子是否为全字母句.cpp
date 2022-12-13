class Solution {
public:
    bool checkIfPangram(string sentence) {
        int state = 0;
        for(auto c : sentence) {
            state |= 1 << (c - 'a');
        }
        return state == (1 << 26) - 1;
    }
};