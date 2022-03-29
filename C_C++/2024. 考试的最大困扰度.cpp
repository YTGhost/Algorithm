class Solution {
public:
    int cnt;
    string str;
    int maxConsecutiveAnswers(string answerKey, int k) {
        cnt = k;
        str = answerKey;
        return max(getRes('T'), getRes('F'));
    }
    int getRes(char c) {
        int n = str.length();
        int k = 0;
        int res = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(str[j] == c) k++;
            while(k > cnt) {
                if(str[i] == c) {
                    k--;
                }
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};