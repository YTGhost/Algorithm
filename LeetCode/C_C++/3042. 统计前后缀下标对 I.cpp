class Solution {
public:
    bool isPrefixAndSuffix(string& str1, string& str2) {
        // 检查 str1 是否足够短以成为 str2 的前缀和后缀
        if (str1.length() > str2.length()) {
            return false;
        }

        // 检查前缀
        if (str2.substr(0, str1.length()) != str1) {
            return false;
        }

        // 检查后缀
        if (str2.substr(str2.length() - str1.length()) != str1) {
            return false;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isPrefixAndSuffix(words[i], words[j])) {
                    res++;
                }
            }
        }
        return res;
    }
};