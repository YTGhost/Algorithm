class Solution {
public:
    int minSwaps(vector<int>& data) {
        int cnt = 0;
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == 1) cnt++;
        }
        int sum = 0, res = 0;
        for(int i = 0; i < cnt; i++) {
            if(data[i] == 0) sum++;
        }
        res = sum;
        for(int i = 1; i + cnt - 1 < data.size(); i++) {
            if(data[i - 1] == 0) sum--;
            if(data[i + cnt - 1] == 0) sum++;
            res = min(res, sum);
        }
        return res;
    }
};