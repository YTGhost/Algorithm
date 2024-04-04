#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for(int j = 1; j <= n; j++) {
            s[i][j] = row[j - 1] - '0', s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for(int k = 1; k <= n; k++) {
        int res = 0;
        for(int i = k; i <= n; i++) {
            for(int j = k; j <= n; j++) {
                int x = i - k, y = j - k;
                int total = k * k;
                int sum = s[i][j] - s[x][j] - s[i][y] + s[x][y];
                int rest = total - sum;
                if(rest == sum) {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}