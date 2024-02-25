#include <iostream>
#include <algorithm>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int week[7];

int main()
{
    int n;
    cin >> n;
    
    int days = 0;
    for(int year = 1900; year < 1900 + n; year++)
    {
        for(int i = 1; i <= 12; i++)
        {
            week[(days + 12) % 7]++;
            days += month[i];
            if(i == 2) {
                if(year % 4 == 0 && year % 100 || year % 400 == 0)
                    days++;
            }
        }
    }
    for(int i = 5, j = 0; j < 7; i = (i+1) % 7, j++)
        cout << week[i] << " ";
    cout << endl;
    return 0;
}