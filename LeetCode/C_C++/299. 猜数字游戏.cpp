class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> hash(10, 0);
        int a = 0, b = 0;
        for(auto c : secret) {
            hash[c - '0']++;
        }
        for(int i = 0; i < guess.size(); i++) {
            if(secret[i] == guess[i]) {
                a++;
                hash[secret[i] - '0']--;
            }
        }
        for(int i = 0; i < guess.size(); i++) {
            if(secret[i] != guess[i] && hash[guess[i] - '0']) {
                b++;
                hash[guess[i] - '0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};