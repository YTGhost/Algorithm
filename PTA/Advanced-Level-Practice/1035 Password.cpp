#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;

struct account {
    string name, password;
}a;

vector<account> t;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        string name, password;
        cin >> name >> password;
        int sign = 0;
        for(int i = 0; i < password.length(); i++)
        {
            if(password[i] == '1') password[i] = '@', sign = 1;
            else if(password[i] == '0') password[i] = '%', sign = 1;
            else if(password[i] == 'l') password[i] = 'L', sign = 1;
            else if(password[i] == 'O') password[i] = 'o', sign = 1;
        }
        if(sign) {
            t.push_back({name, password});
        }
    }
    if(t.empty()) {
        if(n == 1) {
            printf("There is %d account and no account is modified", n);
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        cout << t.size() << endl;
        for(int i = 0; i < t.size(); i++)
            cout << t[i].name << " " << t[i].password << endl;
    }
    return 0;
}