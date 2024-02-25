#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<char>>> list;
vector<string> wordList;

void printWord(string word)
{
    int len = word.length();
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < len; j++) {
            int idx = word[j] - 'A';
            for(int k = 0; k < 5; k++) {
                printf("%c", list[idx][i][k]);
            }
            if(j != len - 1) printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    for(int i = 0; i < 26; i++) {
        vector<vector<char>> letter(7, vector<char>(5));
        for(int j = 0; j < 7; j++) {
            for(int k = 0; k < 5; k++) {
                cin >> letter[j][k];
            }
        }
        list.push_back(letter);
    }
    getchar();
    string str;
    getline(cin, str);
    string word;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] < 'A' || str[i] > 'Z') continue;
        while(str[i] >= 'A' && str[i] <= 'Z') {
            word += str[i++];
        }
        wordList.push_back(word);
        word = "";
    }
    for(int i = 0; i < wordList.size(); i++) {
        printWord(wordList[i]);
        if(i != wordList.size() - 1) printf("\n");
    }
    return 0;
}