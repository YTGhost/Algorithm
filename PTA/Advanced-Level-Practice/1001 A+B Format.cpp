#include <iostream>
using namespace std;

int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    sum = a + b;
    string str = to_string(sum);
    int length = str.length();
    int lengthNum = length;
    for(int k = 1, i = 0; i < length; i++)
    {
        cout << str[i];
        if(str[i] == '-'){
            lengthNum--;
            continue;
        }
        if((lengthNum-k)%3 == 0 && i != length-1) cout << ',';
        k++;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    int cnt = 0;
    int flag = c >= 0 ? 0 : 1;
    string res;
    if(c == 0) res = "0";
    while(c) {
        if(cnt == 3) {
            res = "," + res;
            cnt = 0;
        }
        res = to_string(abs(c % 10)) + res;
        c /= 10;
        cnt++;
    }
    if(flag) res = "-" + res;
    cout << res << endl;
    return 0;
}