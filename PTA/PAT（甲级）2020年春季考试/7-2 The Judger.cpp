#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

const int N = 15, M = 1010;
int num1, num2;
int failed[N];
int n, m;
int g[N][M];
int cnt;
int maxNum;
unordered_set<int> exist;

bool judge(int x)
{
    for(auto num : exist) {
        if(exist.count(x + num)) return true;
    }
    return false;
}

int main()
{
    cin >> num1 >> num2;
    maxNum = max(num1, num2);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    exist.insert(num1);
    exist.insert(num2);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(failed[j]) continue;
            int x = g[j][i];
            if(x > maxNum || !judge(x) || exist.count(x)) {
                failed[j] = 1;
                cnt++;
                printf("Round #%d: %d is out.\n", i, j);
            } else {
                exist.insert(x);
            }
        }
    }
    if(cnt == n) printf("No winner.\n");
    else {
        printf("Winner(s):");
        for(int i = 1; i <= n; i++) {
            if(failed[i] == 0)
                printf(" %d", i);
        }
        cout << endl;
    }
    return 0;
}