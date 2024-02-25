#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1010;
int n;
double d;
double s[N];
double w[N];

struct Cake{
    double s, w;
    
    bool operator< (const Cake& t) const {
        return w / s > t.w / t.s;
    }
}C[N];

int main()
{
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> C[i].s;
    for(int i = 0; i < n; i++) cin >> C[i].w;
    
    sort(C, C + n);
    
    double res = 0;
    for(int i = 0; i < n; i++) {
        if(d <= C[i].s) {
            res += C[i].w / C[i].s * d;
            break;
        } else {
            res += C[i].w;
            d -= C[i].s;
        }
    }
    printf("%.2lf", res);
    return 0;
}