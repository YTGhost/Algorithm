class Solution {
    public:
        int findSpecialInteger(vector<int>& arr) {
            int n = arr.size();
            int l = 0;
            while (l < n) {
                int r = l + 1;
                while (r < n && arr[r] == arr[l]) {
                    r++;
                }
                if (4 * (r - l) > n) return arr[l];
                l = r;
            }
            return 0;
        }
    };