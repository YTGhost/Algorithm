class Solution {
public:
    bool check(string str) {
        int n = str.length();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] >= '0' && str[i] <= '9') return false;
            if(str[i] == '-' && (i == 0 || i == n - 1)) return false;
            if(str[i] == '-' && (str[i - 1] < 'a' || str[i - 1] > 'z')) return false;
            if(str[i] == '-' && (str[i + 1] < 'a' || str[i + 1] > 'z')) return false;
            if(str[i] == '-') cnt++;
            if(cnt > 1) return false;
            if(i != n - 1 && (str[i] == '!' || str[i] == '.' || str[i] == ',')) return false;
        }
        return true;
    }
    int countValidWords(string sentence) {
        int res = 0, n = sentence.length();
        int l = 0, r = 0;
        while(true) {
            while(l < n && sentence[l] == ' ') {
                l++;
            }
            if(l >= n) break;
            r = l + 1;
            while(r < n && sentence[r] != ' ') {
                r++;
            }
            if(check(sentence.substr(l, r - l))) {
                res++;
            }
            l = r + 1;
        }
        return res;
    }
};