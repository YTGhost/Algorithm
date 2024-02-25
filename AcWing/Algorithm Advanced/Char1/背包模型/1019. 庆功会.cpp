#include <iostream>
#include <algorithm>
using namespace std;

const int N = 6010;
int f[N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for(int i = 1; i <= n; i++)
        {
            for(int k = 1; k <= s; k *= 2)
            {
                for(int j = m; j >= k * v; j--)
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
        }
        if(s)
        {
            for(int j = m; j >= s * v; j--)
                f[j] = max(f[j], f[j - s * v] + s * w);
        }
    }
    cout << f[m] << endl;
    return 0;
}

// 朴素
// #include <iostream>
// #include <algorithm>
// using namespace std;

// const int N = 6010;
// int f[N][N];

// int main()
// {
//     int n, m;
//     cin >> n >> m;
    
//     for(int i = 1; i <= n; i++)
//     {
//         int v, w, s;
//         cin >> v >> w >> s;
//         for(int j = 1; j <= m; j++)
//             for(int k = 0; k <= s && k*v <= j; k++)
//                 f[i][j] = max(f[i][j], f[i-1][j-k*v] + k * w);
//     }
//     cout << f[n][m] << endl;
//     return 0;
// }