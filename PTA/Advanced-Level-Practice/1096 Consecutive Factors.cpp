#include <iostream>
#include <vector>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> res;
    for(int i = 2; i <= n / i; i++) {
        int j, t = n;
        vector<int> temp;
        for(j = i; j <= n; j++) {
            if(t % j == 0) {
                temp.push_back(j);
                t /= j;
            } else {
                break;
            }
        }
        if(temp.size() > res.size()) res = temp;
    }
    if(res.empty()) res.push_back(n);
    cout << res.size() << endl;
    printf("%d", res[0]);
    for(int i = 1; i < res.size(); i++) printf("*%d", res[i]);
    cout << endl;
    return 0;
}