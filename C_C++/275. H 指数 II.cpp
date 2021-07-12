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