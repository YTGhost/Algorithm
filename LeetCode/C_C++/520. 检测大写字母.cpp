class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for(auto c : word) {
            if(c >= 'A' && c <= 'Z') cnt++;
        }
        if(cnt == word.length() || cnt == 0) return true;
        else if(cnt == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;
        else return false;
    }
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        int sign;
        if(word.length() == 1) return true;
        if(word[0] >= 'A' && word[0] <= 'Z')
        {
            if(word[1] >= 'A' && word[1] <= 'Z') sign = 1;
            else sign = 3;
        }else if(word[1] < 'a' || word[1] > 'z') return false;
        else sign = 2;
        for(int i = 2; i < word.length(); i++)
        {
            char t = word[i];
            if(sign == 1 && (word[i] < 'A' || word[i] >'Z')) return false;
            else if((sign == 2 || sign == 3) && (word[i] < 'a' || word[i] > 'z')) return false;
        }
        return true;
    }
};