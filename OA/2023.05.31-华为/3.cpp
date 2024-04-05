#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> s[i][j], s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int cnt = INT_MAX, profit = INT_MIN;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int x = i; x <= n; x++) {
                for(int y = j; y <= m; y++) {
                    int num = (x - i + 1) * (y - j + 1);
                    int sum = s[x][y] - s[i - 1][y] - s[x][j - 1] + s[i - 1][j - 1] - num * 5;
                    if(sum > profit) {
                        profit = sum;
                        cnt = num;
                    } else if(sum == profit) {
                        cnt = min(cnt, num);
                    }
                }
            }
        }
    }
    cout << cnt << " " << profit << endl;
    return 0;
}