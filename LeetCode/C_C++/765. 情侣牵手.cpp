class Solution {
public:
    int p[70];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    void toUnion(int a, int b) {
        p[find(a)] = p[find(b)];
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        for(int i = 0; i < row.size(); i++) {
            p[i] = i;
        }
        for(int i = 0; i < 2 * n; i += 2) {
            toUnion(row[i] / 2, row[i + 1] / 2);
        }
        int cnt = 0;
        for(int i = 0; i < row.size(); i++) {
            if(i == find(i)) cnt++;
        }
        return row.size() - cnt;
    }
};