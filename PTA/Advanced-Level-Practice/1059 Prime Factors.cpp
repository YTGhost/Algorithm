#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    printf("%d=", n);
    bool isFirst = true;
    
    if(n == 1) printf("%d", n);
    else {
        for(int i = 2; i <= n / i; i++) {
            int cnt = 0;
            if(n % i == 0) {
                while(n % i == 0) n /= i, cnt++;
                if(isFirst) isFirst = false;
                else printf("*");
                printf("%d", i);
                if(cnt > 1) printf("^%d", cnt);
            }
        }
        if(n > 1) {
            if(!isFirst) printf("*");
            printf("%d", n);
        }
    }
    return 0;
}