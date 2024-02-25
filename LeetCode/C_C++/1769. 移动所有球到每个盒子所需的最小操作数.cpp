class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left = boxes[0] - '0', right = 0, operation = 0;
        for(int i = 1; i < n; i++) {
            if(boxes[i] == '1') {
                right++;
                operation += i;
            }
        }
        vector<int> res(n);
        res[0] = operation;
        for(int i = 1; i < n; i++) {
            operation += left - right;
            if(boxes[i] == '1') {
                left++;
                right--;
            }
            res[i] = operation;
        }
        return res;
    }
};