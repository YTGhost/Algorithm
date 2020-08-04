class Solution {
public:
    const static int N = 100010;
    int h[N], e[N], ne[N], idx;
    int q[N], d[N];
    int n;

    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    bool topsort() {
        int hh = 0, tt = -1;

        for(int i = 0; i < n; i++)
            if(!d[i]) q[++tt] = i;

        while(hh <= tt)
        {
            int t = q[hh++];
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                d[j]--;
                if(!d[j]) q[++tt] = j;
            }
        }
        return tt == n-1;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        memset(h, -1, sizeof(h));
        for(auto x : prerequisites)
        {
            add(x[1], x[0]);
            d[x[0]]++;
        }
        return topsort();
    }
};