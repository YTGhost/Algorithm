#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int e[M], ne[M], h[N], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n1, n2, m;
    cin >> n1, n2, m;

    memset(h, -1, sizeof(h));
    
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    
    int ans = 0;
    for(int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof(st));
        if(find(i)) ans++;
    }
    
    cout << ans << endl;
    return 0;
}