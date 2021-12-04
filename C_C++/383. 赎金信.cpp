class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(auto c : magazine) {
            m[c]++;
        }
        for(auto c : ransomNote) {
            if(m[c]) m[c]--;
            else return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int sign[26];
        memset(sign, 0, sizeof(sign));
        for(int i = 0; i < magazine.length(); i++) sign[magazine[i] - 'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
        {
            if(sign[ransomNote[i] - 'a']) sign[ransomNote[i] - 'a']--;
            else return false;
        }
        return true;
    }
};