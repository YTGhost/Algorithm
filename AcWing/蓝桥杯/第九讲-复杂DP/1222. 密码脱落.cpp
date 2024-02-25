#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N];

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    
    for(int len = 1; len <= n; len++)
    {
        for(int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if(len == 1) {
                f[i][j] = 1;
            } else {
                f[i][j] = max(f[i][j-1], f[i+1][j]);
                if(str[i] == str[j]) f[i][j] = max(f[i][j], f[i+1][j-1] + 2);
            }
        }
    }
    cout << n - f[0][n-1] << endl;
    return 0;
}