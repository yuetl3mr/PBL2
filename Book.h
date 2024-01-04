#include <bits/stdc++.h>
using namespace std;

class Book{
    protected:
        string BookNo;
        string Name;
        string Author;
        int Category;
        int Avalible;
        int Total;
        string BookCategory[12] = 
        {"Others", "Horror", "Fantasy", "Comics", "Religion", "History", 
        "Romance", "Biography", "Sience", "Computer", "Self-Help", "Novel"};
    public:
        //constructor
        Book();
        Book(string, string, string, int, int, int);
        Book(string);
        //deconstructor
        ~Book();
        //overload operator 
        friend istream& operator>>(istream&, Book&);
        friend const ostream& operator<<(ostream&, const Book&);
        friend const string& BookInfo(const Book&);
        //...
        int GetCategory();
        int getTotal();
        const int getAvali(const Book&);
        int getAvali();
        string printFile();
        void setAvali(bool);       
        bool FindAuthor(string);
        bool FindCate(int);
        string getName();
};