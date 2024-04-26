#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6, m = 7;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if(a[0][3] == '|' && a[5][3] == '.') {
        cout << "m" << endl;
    } else if(a[0][3] == '|' && a[5][3] == '|') {
        cout << "p" << endl;
    } else {
        cout << "o" << endl;
    }
    return 0;
}