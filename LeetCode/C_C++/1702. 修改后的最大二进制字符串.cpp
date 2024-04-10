class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.length();
        if(n == 1) return binary;
        int idx = 0;
        while(idx < n && binary[idx] == '1') {
            idx++;
        }
        if(idx == n) return binary;
        int cnt = 0;
        for(int i = idx; i < n; i++) {
            if(binary[i] == '1') cnt++;
        }
        return string(n - cnt - 1, '1') + "0" + string(cnt, '1');
    }
};