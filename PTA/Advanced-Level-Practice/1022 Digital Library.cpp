#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Book {
    string id, name, author;
    set<string> keywords;
    string publisher, year;
};

int main()
{
    int n;
    cin >> n;
    vector<Book> books;
    for(int i = 0; i < n; i++)
    {
        string id, name, author, publisher, year;
        cin >> id;
        getchar();
        getline(cin, name);
        getline(cin, author);
        string line;
        getline(cin, line);
        stringstream ssin(line);
        string keyword;
        set<string> keywords;
        while(ssin >> keyword) keywords.insert(keyword);
        getline(cin, publisher);
        getline(cin, year);
        books.push_back({id, name, author, keywords, publisher, year});
    }
    int m;
    cin >> m;
    getchar();
    string line;
    while(m--)
    {
        getline(cin, line);
        char t = line[0];
        string info = line.substr(3);
        vector<string> res;
        cout << line << endl;
        
        if(t == '1') {
            for(auto &book : books)
                if(book.name == info)
                    res.push_back(book.id);
        } else if(t == '2') {
            for(auto &book : books)
                if(book.author == info)
                    res.push_back(book.id);
        } else if(t == '3') {
            for(auto &book : books)
                if(book.keywords.count(info))
                    res.push_back(book.id);
        } else if(t == '4') {
            for(auto &book : books)
                if(book.publisher == info)
                    res.push_back(book.id);
        } else if(t == '5') {
            for(auto &book : books)
                if(book.year == info)
                    res.push_back(book.id);
        }
        if(res.empty()) {
            cout << "Not Found" << endl;
        } else {
            sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << endl;
        }
    }
    return 0;
}