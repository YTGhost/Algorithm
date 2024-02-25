#include <iostream>
using namespace std;

const int N = 1010;
const int M = 500000;
int p[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct Edge {
    int a, b;
}e[M];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[i] = {a, b};
    }
    while(k--)
    {
        int x;
        cin >> x;
        for(int i = 1; i <= n; i++) p[i] = i;
        int cnt = n-1;
        for(int i = 0; i < m; i++)
        {
            int a = e[i].a, b = e[i].b;
            if(x != a && x != b)
            {
                int pa = find(a), pb = find(b);
                if(pa != pb)
                {
                    p[pa] = pb;
                    cnt--;
                }
            }
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}