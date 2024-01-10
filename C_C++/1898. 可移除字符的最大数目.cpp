class Solution {
public:
    bool check(vector<int>& removable, int k, string s, string p) {
        vector<bool> status(s.size(), true);
        for(int i = 0; i < k; i++) {
            status[removable[i]] = false;
        }
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(status[i] && p[j] == s[i]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size(), m = p.size();
        int start = 0, end = removable.size() + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(removable, mid, s, p)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start - 1;
    }
};