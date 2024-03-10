class Solution {
public:
    string capitalizeTitle(string title) {
        int l = 0, n = title.length();
        for(int r = 0; r < n; r++) {
            while(r < n && title[r] != ' ') r++;
            int len = r - l;
            if(len == 1 || len == 2) {
                while(l != r) {
                    if(title[l] >= 'A' && title[l] <= 'Z') {
                        title[l] = 'a' + title[l] - 'A';
                    }
                    l++;
                }
            } else {
                if(title[l] >= 'a' && title[l] <= 'z') {
                    title[l] = 'A' + title[l] - 'a';
                }
                l++;
                while(l != r) {
                    if(title[l] >= 'A' && title[l] <= 'Z') {
                        title[l] = 'a' + title[l] - 'A';
                    }
                    l++;
                }
            }
            l++;
        }
        return title;
    }
};