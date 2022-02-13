class Solution {
public:
    int hash[26];
    int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        for(auto c : text) {
            hash[c - 'a']++;
        }
        res = min(res, hash['a' - 'a']);
        res = min(res, hash['b' - 'a']);
        res = min(res, hash['l'- 'a'] / 2);
        res = min(res, hash['o' - 'a'] / 2);
        res = min(res, hash['n' - 'a']);
        return res;
    }
};