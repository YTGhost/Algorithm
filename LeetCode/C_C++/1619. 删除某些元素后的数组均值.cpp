class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double sum = 0;
        for(int i = n / 20; i < n * 19 / 20; i++) {
            sum += arr[i];
        }
        return sum / (n * 9 / 10);
    }
};