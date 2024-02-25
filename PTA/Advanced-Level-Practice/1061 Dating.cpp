#include <iostream>
using namespace std;

string date[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    
    int sign = 1;
    for(int i = 0; i < str1.size() && i < str2.size(); i++) {
        if(sign == 1 && str1[i] >= 'A' && str1[i] <= 'G' && str1[i] == str2[i]) {
            printf("%s ", date[str1[i] - 'A'].c_str());
            sign = 2;
        } else if(sign == 2  && str1[i] == str2[i]) {
            if(str1[i] >= '0' && str1[i] <= '9') {
                printf("0%d:", str1[i] - '0');
                sign = 3;
            } else if(str1[i] >= 'A' && str1[i] <= 'N') {
                printf("%d:",str1[i] - 'A' + 10);
                sign = 3;
            }
            if(sign == 3) break;
        }
    }
    for(int i = 0; i < str3.size() && i < str4.size(); i++) {
        if(str3[i] >= 'a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z') {
            if(str3[i] == str4[i]) {
                if(i >= 0 && i <= 9) {
                    printf("0");
                }
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}