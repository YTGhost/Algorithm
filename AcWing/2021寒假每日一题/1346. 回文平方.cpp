#include <iostream>
#include <algorithm>
using namespace std;

char getChar(int num)
{
    if(num <= 9) return '0' + num;
    else return num - 10 + 'A';
}

string changeToB(int num, int b)
{
    string res;
    while(num) res += getChar(num % b), num /= b;
    reverse(res.begin(), res.end());
    return res;
}

bool check(string num)
{
    for(int i = 0, j = num.size()-1; i < j; i++, j--)
        if(num[i] != num[j]) return false;
    return true;
}

int main()
{
    int b;
    cin >> b;
    
    for(int i = 1; i <= 300; i++)
    {
        string num = changeToB(i * i, b);
        if(check(num)) {
            cout << changeToB(i, b) << " " << num << endl;
        }
    }
    return 0;
}