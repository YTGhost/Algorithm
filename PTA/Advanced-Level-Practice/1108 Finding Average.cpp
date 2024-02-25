#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    double sum = 0;
    int cnt = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string num;
        cin >> num;
        double t;
        bool success = true;
        
        try{
            size_t idx;
            t = stof(num, &idx);
            if(idx < num.size()) success = false;
        }
        catch(...) {
            success = false;
        }
        
        if(t < -1000 || t > 1000) success = false;
        int k = num.find('.');
        if(k != -1 && num.size() - k > 3) success = false;
        if(success) cnt++, sum += t;
        else printf("ERROR: %s is not a legal number\n", num.c_str());
    }
    if(cnt > 1) {
        printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    } else if(cnt == 1) {
        printf("The average of 1 number is %.2lf\n", sum);
    } else {
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}