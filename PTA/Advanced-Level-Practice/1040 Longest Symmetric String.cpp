#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int res = 0;
    for(int i = 0; i < str.length(); i++) {
        int l = i - 1, r = i + 1;
        while(l >= 0 && r < str.length() && str[l] == str[r]) l--, r++;
        res = max(res, r - l - 1);
        
        l = i, r = i + 1;
        while(l >= 0 && r < str.length() && str[l] == str[r]) l--, r++;
        res = max(res, r - l - 1);
    }
    cout << res << endl;
    return 0;
}