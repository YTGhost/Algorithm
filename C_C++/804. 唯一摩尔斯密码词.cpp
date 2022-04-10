class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> hash;
        vector<string> table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word : words) {
            string temp = "";
            for(int i = 0; i < word.length(); i++) {
                temp += table[word[i] - 'a'];
            }
            hash.insert(temp);
        }
        return hash.size();
    }
};