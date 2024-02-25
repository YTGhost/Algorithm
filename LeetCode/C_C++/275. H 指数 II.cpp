class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 1, end = n + 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(citations[n - mid] >= mid) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start - 1;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 1, r = n;
        while(l <= r) {
            int mid = l + r >> 1;
            if(citations[n - mid] >= mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int i = citations.size() - 1;
        while(i >= 0 && citations[i] > h) {
            i--;
            h++;
        }
        return h;
    }
};