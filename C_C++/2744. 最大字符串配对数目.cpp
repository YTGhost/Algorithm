class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<vector<bool>> hash(26, vector<bool>(26, false));
        int res = 0;
        for(auto word : words) {
            int x = word[0] - 'a';
            int y = word[1] - 'a';
            if(hash[y][x]) {
                res++;
            } else {
                hash[x][y] = true;
            }
        }
        return res;
    }
};