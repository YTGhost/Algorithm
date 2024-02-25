#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int p[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++; 
}

int getDepth(int root, int father)
{
    int depth = 0;
    for(int i = h[root]; ~i; i = ne[i]) {
        int j = e[i];
        if(j == father) continue;
        depth = max(depth, getDepth(j, root) + 1);
    }
    return depth;
}

int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++) p[i] = i;
    int k = n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        
        if(find(a) != find(b)) {
            k--;
            p[find(a)] = find(b);
        }
        add(a, b), add(b, a);
    }
    if(k > 1) {
        printf("Error: %d components", k);
    } else {
        int maxDepth = -1;
        vector<int> res;
        for(int i = 1; i <= n; i++) {
            int depth = getDepth(i, -1);
            if(depth > maxDepth) {
                res.clear();
                maxDepth = depth;
                res.push_back(i);
            } else if (depth == maxDepth) {
                res.push_back(i);
            }
        }
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
