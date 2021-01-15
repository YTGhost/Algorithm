class Solution {
public:
    int p[20005];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void toUnion(int x, int y) {
        p[find(x)] = find(y);
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i = 0; i < 20005; i++) p[i] = i;
        for(auto stone : stones)
            toUnion(stone[0], stone[1] + 10001);
        set<int> s;
        for(auto stone : stones)
            s.insert(find(stone[0]));
        return n - s.size();
    }
};