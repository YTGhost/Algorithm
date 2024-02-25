class Solution {
public:
    unordered_set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string toGoatLatin(string sentence) {
        string res = "";
        string word = "";
        int cnt = 0;
        int n = sentence.length();
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && sentence[j] != ' ') {
                j++;
            }
            word = sentence.substr(i, j - i);
            cnt++;
            if(cnt != 1) {
                res += " ";
            }
            if(s.count(word[0])) {
                res += word + "ma" + string(cnt, 'a');
            } else {
                char t = word[0];
                res += word.substr(1) + t + "ma" + string(cnt, 'a');
            }
            i = j;
        }
        return res;
    }
};