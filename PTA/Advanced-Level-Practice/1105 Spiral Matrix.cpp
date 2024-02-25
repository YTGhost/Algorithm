#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10010;
int a[N];

int main()
{
    int n, r, c;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n / i; i++) {
        if(n % i == 0) {
            r = n / i;
            c = i;
        }
    }
    sort(a, a + n, greater<int>());
    vector<vector<int>> res(r, vector<int>(c));
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for(int i = 0, x = 0, y = 0, d = 0; i < n; i++) {
        res[x][y] = a[i];
        int newX = x + dx[d], newY = y + dy[d];
        if(newX < 0 || newX >= r || newY < 0 || newY >= c || res[newX][newY]) {
            d = (d + 1) % 4;
            newX = x + dx[d], newY = y + dy[d];
        }
        x = newX, y = newY;
    }
    for(int i = 0; i < r; i++)
    {
        cout << res[i][0];
        for(int j = 1; j < c; j++)
        {
            cout << " " << res[i][j];
        }
        cout << endl;
    }
    return 0;
}