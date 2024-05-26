class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        function<void(int)> push_pq = [&](int val) {
            if(pq.size() < k) {
                pq.push(val);
            } else if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        };
        push_pq(matrix[0][0]);
        for(int i = 1; i < m; i++) {
            matrix[i][0] ^= matrix[i - 1][0];
            push_pq(matrix[i][0]);
        }
        for(int i = 1; i < n; i++) {
            matrix[0][i] ^= matrix[0][i - 1];
            push_pq(matrix[0][i]);
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
                push_pq(matrix[i][j]);
            }
        }
        return pq.top();
    }
};