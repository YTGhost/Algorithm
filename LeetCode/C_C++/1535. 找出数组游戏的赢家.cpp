class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int res = arr[0], cnt = 0;
        for(int i = 1; i < n && cnt < k; i++) {
            if(res < arr[i]) {
                res = arr[i];
                cnt = 0;
            }
            cnt++;
        }
        return res;
    }
};