class Solution {
public:
    int p[26];
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < equations.size(); i++)
        {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if(p[a] == 0) p[a] = a;
            if(p[b] == 0) p[b] = b;
            if(equations[i][1] == '=') p[find(a)] = find(b);
        }
        for(int i = 0; i < equations.size(); i++)
        {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if(equations[i][1] == '!' && find(a) == find(b)) return false;
        }
        return true;
    }
};