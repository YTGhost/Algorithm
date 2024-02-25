#include <iostream>
using namespace std;

const int N = 200;
int st[N];

int main()
{
    int k;
    string str;
    cin >> k >> str;
    for(int i = 0, j = i + 1; i < str.size(); i++) {
        while(i < str.size() && str[i] == str[j]) j++;
        int len = j - i;
        if(len % k) st[str[i]] = 1;
        i = j - 1;
    }
    string res;
    for(int i = 0; i < str.size(); i++) {
        if(!st[str[i]]) {
            cout << str[i];
            st[str[i]] = 2;
        }
        res += str[i];
        if(st[str[i]] != 1) i += k-1;
    }
    cout << endl << res << endl;
    return 0;
}