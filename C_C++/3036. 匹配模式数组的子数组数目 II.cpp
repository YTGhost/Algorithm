class Solution {
public:
    vector<int> calc_max_match(vector<int>& s) {
        vector<int> match(s.size());
        int c = 0;
        for (int i = 1; i < s.size(); i++) {
            char v = s[i];
            while (c && s[c] != v) {
                c = match[c - 1];
            }
            if (s[c] == v) {
                c++;
            }
            match[i] = c;
        }
        return match;
    }
    int kmp_search(vector<int>& text, vector<int>& pattern) {
        vector<int> match = calc_max_match(pattern);
        int match_cnt = 0, c = 0;
        for (int i = 0; i < text.size(); i++) {
            char v = text[i];
            while (c && pattern[c] != v) {
                c = match[c - 1];
            }
            if (pattern[c] == v) {
                c++;
            }
            if (c == pattern.size()) {
                match_cnt++;
                c = match[c - 1];
            }
        }
        return match_cnt;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int> t(n - 1);
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                t[i] = 1;
            } else if(nums[i] == nums[i + 1]) {
                t[i] = 0;
            } else {
                t[i] = -1;
            }
        }
        int res = kmp_search(t, pattern);
        return res;
    }
};