#include <iostream>
using namespace std;

const int N = 105;
int a[N];

int main()
{
    int level = 0, res = 0, n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(level != x) {
            if(x < level) {
                res += (level - x) * 4;
            } else {
                res += (x - level) * 6;
            }
            res += 5;
            level = x;

        } else {
            res += 5;
        }
    }
    cout << res << endl;
    return 0;
}