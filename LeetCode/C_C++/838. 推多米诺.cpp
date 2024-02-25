class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size(), i = 0;
        char left = 'L';
        while(i < n) {
            int j = i;
            while(j < n && dominoes[j] == '.') {
                j++;
            }
            char right = j < n ? dominoes[j] : 'R';
            if(left == right) {
                while(i < j) {
                    dominoes[i++] = right;
                }
            } else if(left == 'R' && right == 'L') {
                int k = j - 1;
                while(i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            left = right;
            i = j + 1;
        }
        return dominoes;
    }
};