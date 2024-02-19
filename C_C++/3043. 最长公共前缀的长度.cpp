class Solution {
public:
    int countDigits(int number) {
        // 如果是0，直接返回1位
        if (number == 0) {
            return 1;
        }
        // 对于负数，先转换为正数
        number = abs(number);
        // 计算位数并返回结果
        return static_cast<int>(log10(number)) + 1;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        unordered_set<int> st;
        for(auto num : arr1) {
            while(num) {
                st.insert(num);
                num /= 10;
            }
        }
        for(auto num : arr2) {
            while(num) {
                if(st.count(num)) {
                    res = max(res, countDigits(num));
                }
                num /= 10;
            }
        }
        return res;
    }
};