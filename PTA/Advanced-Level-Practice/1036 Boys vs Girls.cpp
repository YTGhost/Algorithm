#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string fName, mName;
    string fId, mId;
    int fScore, mScore;
    for(int i = 0; i < n; i++)
    {
        string name, sex, id;
        int score;
        cin >> name >> sex >> id >> score;
        if(sex == "M") {
            if(mName.empty()) {
                mName = name;
                mId = id;
                mScore = score;
            } else {
                if(score < mScore) {
                    mName = name;
                    mId = id;
                    mScore = score;
                }
            }
        } else {
            if(fName.empty()) {
                fName = name;
                fId = id;
                fScore = score;
            } else {
                if(score > fScore) {
                    fName = name;
                    fId = id;
                    fScore = score;
                }
            }
        }
    }
    if(!fName.empty()) {
        cout << fName << " " << fId << endl;
    } else {
        cout << "Absent" << endl;
    }
    if(!mName.empty()) {
        cout << mName << " " << mId << endl;
    } else {
        cout << "Absent" << endl;
    }
    if(!fName.empty() && !mName.empty()) {
        cout << fScore - mScore << endl;
    } else {
        cout << "NA" << endl;
    }
    return 0;
}