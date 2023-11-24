#include <bits/stdc++.h>
using namespace std;

class Book{
    protected:
        string BookNo;
        string Name;
        string Author;
        int Category;
        bool Status;
        string BookCategory[12] = 
        {"Others", "Horror", "Fantasy", "Comics", "Religion", "History", 
        "Romance", "Biography", "Sience", "Computer", "Self-Help", "Novel"};
    public:
        //constructor
        Book();
        Book(string, string, string, int, bool);
        Book(string);
        //deconstructor
        ~Book();
        //overload operator 
        friend istream& operator>>(istream&, Book&);
        friend const ostream& operator<<(ostream&, const Book&);
        friend const string& BookInfo(const Book&);
        friend const bool& bookStatus(const Book&);
        //...
        int GetCategory();
        bool GetStatus();
        void printFile();
        
};