#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 40;
int g[N][N], st[1010];

bool checkRow(int n)
{
    for(int i = 1; i <= n; i++)
    {
        memset(st, 0, sizeof st);
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] > n || g[i][j] < 1) return false;
            else if(st[g[i][j]]) return false;
            else st[g[i][j]] = 1;
        }
    }
    return true; 
}

bool checkCol(int n)
{
    for(int i = 1; i <= n; i++)
    {
        memset(st, 0, sizeof st);
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] > n || g[i][j] < 1) return false;
            else if(st[g[j][i]]) return false;
            else st[g[j][i]] = 1;
        }
    }
    return true;
}

bool checkSub(int n)
{
    int t = n*n;
    for(int i = 1; i <= t; i++)
    {
        int a = 1 + (i-1) / n * n;
        int b = a + n;
        int c = (i-1) % 3 * n + 1;
        int d = c + n;
        memset(st, 0, sizeof st);
        for(int j = a; j < b; j++)
        {
            for(int k = c; k < d; k++)
            {
                if(st[g[j][k]]) return false;
                else st[g[j][k]] = 1;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++)
    {
        int n, t;
        cin >> n;
        t = n*n;
        for(int i = 1; i <= t; i++)
            for(int j = 1; j <= t; j++)
                cin >> g[i][j];
        
        cout << "Case #" << i;
        if(checkRow(t) && checkCol(t) && checkSub(n)) {
            cout << ": Yes" << endl;
        } else {
            cout << ": No" << endl;
        }
    }
    return 0;
}