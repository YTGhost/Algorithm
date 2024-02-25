#include <iostream>
using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;
    string str = "" + to_string(d);
    for(int i = 1; i < n; i++) {
        string t = "";
        char pre = str[0];
        int cnt = 1;
        for(int j = 1; j < str.size(); j++) {
            if(str[j] == pre) {
                cnt++;
            } else {
                t += pre + to_string(cnt);
                pre = str[j];
                cnt = 1;
            }
        }
        if(cnt) {
            t += pre + to_string(cnt);
        }
        str = t;
    }
    printf("%s\n", str.c_str());
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    string d;
    int n;
    cin >> d >> n;
    for(int i = 0; i < n - 1; i++) {
        string next = "";
        for(int i = 0; i < d.length();) {
            int j = i + 1;
            while(j < d.length() && d[i] == d[j]) j++;
            next += d[i] + to_string(j - i);
            i = j;
        }
        d = next;
    }
    cout << d << endl;
    return 0;
}