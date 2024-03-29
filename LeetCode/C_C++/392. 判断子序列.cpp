class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;

        while(i < n && j < m)
        {
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == n; 
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
        {
            return true;
        }
        for(int i = 0, j = 0; i < t.length(); i++)
        {
            if(s[j] == t[i]){
                if(++j == s.length()){
                    return true;
                }
            }
        }
        return false;
    }
};