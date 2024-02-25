class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) {
            return false;
        }
        int hash[26];
        memset(hash, 0, sizeof(hash));
        for(auto c : magazine) {
            hash[c - 'a']++;
        }
        for(auto c : ransomNote) {
            if(!hash[c - 'a']) {
                return false;
            }
            hash[c - 'a']--;
        }
        return true;
    }
};

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