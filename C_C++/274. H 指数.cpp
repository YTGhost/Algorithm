class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int res = 0;
        sort(citations.begin(), citations.end());
        for(int i = n - 1; i >= 0; i--) {
            if(citations[i] > res) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        int i = n - 1;
        while(i >= 0 && citations[i] > h) {
            i--;
            h++;
        }
        return h;
    }
};