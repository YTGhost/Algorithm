#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
int cMax, d, dAvg, n;

struct Stop{
    double p, d;
    
    bool operator< (const Stop& t) const {
        return d < t.d;
    }
}s[N];

int main()
{
    cin >> cMax >> d >> dAvg >> n;
    for(int i = 0; i < n; i++) cin >> s[i].p >> s[i].d;
    s[n] = {0, (double)d};
    
    sort(s, s + n + 1);
    
    if(s[0].d) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    
    int dis = dAvg * cMax;
    double res = 0, oil = 0;
    for(int i = 0; i < n;) {
        int k = -1;
        for(int j = i + 1; j <= n && s[j].d - s[i].d <= dis; j++) {
            if(s[j].p < s[i].p) {
                k = j;
                break;
            } else if(k == -1 || s[j].p < s[k].p) {
                k = j;
            }
        }
        
        if(k == -1) {
            printf("The maximum travel distance = %.2lf\n", s[i].d + dis);
            return 0;
        }
        
        if(s[k].p <= s[i].p) {
            res += ((s[k].d - s[i].d) / dAvg - oil) * s[i].p;
            oil = 0;
            i = k;
        } else {
            res += (cMax - oil) * s[i].p;
            oil = cMax - (s[k].d - s[i].d) / dAvg;
            i = k;
        }
    }
    printf("%.2lf\n", res);
    return 0;
}