#include <iostream>
using namespace std;

const int N = 10010;
int n, m;
int prices[N];
int sum[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> prices[i];
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + prices[i];
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(sum[j] - sum[i] <= m) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}