#include <iostream>
using namespace std;

const int N = 2010, M = 1010;
double t[M], res[N];

int main()
{
    int k, c, d;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int a;
        double b;
        cin >> a >> b;
        if(i == 0) c = a;
        t[a] = b;
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        int a; 
        double b;
        cin >> a >> b;
        if(i == 0) d = a;
        for(int j = c; j >= 0; j--) {
            if(t[j] != 0) {
                res[a + j] += t[j] * b;
            }
        }
    }
    int cnt = 0;
    for(int i = c + d; i >= 0; i--) {
        if(res[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for(int i = c + d; i >= 0; i--) {
        if(res[i] != 0) {
            printf(" %d %.1lf", i, res[i]);
        }
    }
    cout << endl;
    return 0;
}