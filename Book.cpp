#include "Book.h"

Book::Book()
    : BookNo("NULL"), Name("NULL"), Author("NULL"), Category(-1), Total(0)
{
}

Book::Book(string bookno, string name, string author, int cate, int tt)
    : BookNo(bookno), Name(name), Author(author), Category(cate), Total(tt), Avalible(tt)
{
}

Book::Book(string bookno)
    : BookNo(bookno), Name("NULL"), Author("NULL"), Category(-1), Total(1) 
{
}

Book::~Book()
{
}

istream& operator>>(istream& inp, Book& NewBook){
    cout << "\t------------------------\n";
    inp.clear();
    inp.ignore(123, '\n');
    cout << "\tTen sach : "; getline(inp, NewBook.Name);
    cout << "\tTac gia : "; getline(inp, NewBook.Author);
    cout << "\tDanh muc : "; 
    while (!(inp >> NewBook.Category) || NewBook.Category > 12 || NewBook.Category < 0){
        cout << "\tDanh muc khong hop le, vui long nhap lai : ";
        inp.clear();
        inp.ignore(123, '\n');
    }
    cout <<"\tSo luong :"; 
    while (!(inp >> NewBook.Total) || NewBook.Total < 1){
        cout << "\tSo luong phai lon hon 0, vui long nhap lai : ";
        inp.clear();
        inp.ignore(123, '\n');
    }
    return inp;
}

const ostream& operator<<(ostream& outp, const Book& Book){
    cout << "\t"; outp << Book.BookNo;
    cout << "\t"; outp << setw(35) << left << Book.Name; 
    cout << "\t"; outp << setw(27) << left << Book.Author;
    cout << "\t"; outp << setw(15) << left << Book.BookCategory[Book.Category];
    cout << "\t"; outp << Book.Total; //note
    cout << endl;
    return outp;
}

const string& BookInfo(const Book& B){
    return B.BookNo;
}

int Book::GetCategory(){
    return Category;
}

int Book::getTotal(){
    return Total;
}

string Book::printFile(){
    return BookNo + ";" + Name + ";" + Author + ";" + to_string(Category) + ";" + to_string(Total) + ";" + to_string(Avalible);
}

void Book::setAvali(bool t){
    if (t) Avalible--;
    else Avalible++;
}

const int getAvali(const Book& B){
    return B.Avalible;
}

int Book::getAvali(){
    return Avalible;
}