#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int sum = 0;
    for(int i = 0, j = 1; i < len-2; i++)
    {
        if(str[i] != '-') {
            sum += (str[i] - '0') * j;
            j++;
        }
    }
    sum %= 11;
    
    if(sum != str.back() - '0') {
        if(sum == 10 && str.back() == 'X') {
            cout << "Right" << endl;
        } else if(sum != 10){
            str.back() = sum + '0'; 
            cout << str << endl;
        } else {
            str.back() = 'X';
            cout << str << endl;
        }
    } else {
        cout << "Right" << endl;
    }
    return 0;
}