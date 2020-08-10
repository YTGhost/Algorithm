class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, last = 0;
        int p = 0, n = s.size();
        while(p < n)
        {
            int count = 0;
            char c = s[p];
            while(p < n && s[p] == c)
            {
                p++;
                count++;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ans = 0;
        int p = 0, n = s.size();
        while(p < n)
        {
            int count = 0;
            char c = s[p];
            while(p < n && s[p] == c)
            {
                p++;
                count++;
            }
            counts.push_back(count);
        }
        for(int i = 1; i < counts.size(); i++)
            ans += min(counts[i], counts[i-1]);
        return ans;
    }
};