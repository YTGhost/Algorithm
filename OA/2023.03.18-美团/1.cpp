#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1010;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> s(N, vector<int>(N, 0));
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s[x][y]++;
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int res = 0;
    for(int i = a; i <= 1000; i++) {
        for(int j = b; j <= 1000; j++) {
            int x = max(i - a - 1, 0), y = max(j - b - 1, 0);
            res = max(res, s[i][j] - s[x][j] - s[i][y] + s[x][y]);
        }
    }
    cout << res << endl;
    return 0;
}