class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> map;
        char ans = ' ';
        for(auto c : s) map[c]++;
        for(auto c : s) {
            if(map[c] == 1) {
                ans = c;
                break;
            }
        }
        return ans;
    }
};