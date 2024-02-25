#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

int f[N][N];

bool check(string t, string str, int n, int m, int op)
{
    for(int i = 1; i <= n; i++) f[i][0] = i;
    for(int i = 1; i <= m; i++) f[0][i] = i;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
            if(t[i] != str[j]) f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
            else f[i][j] = min(f[i][j], f[i-1][j-1]);
        }
    if(f[n][m] <= op) return true;
    else return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> t(n+1);
    for(int i = 1; i <= n; i++)
    {
      cin >> t[i];
      t[i] = " " + t[i];
    } 
    
    while(m--)
    {
        string str;
        int op, cnt = 0;
        cin >> str >> op;
        str = " " + str;
        for(int i = 1; i <= n; i++)
            if(check(t[i], str, t[i].length()-1, str.length()-1, op)) cnt++;
        cout << cnt << endl;
    }
    return 0;
}