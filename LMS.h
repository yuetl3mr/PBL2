#include "Book.h"
#include "Reader.h"
#include "Loan.h"

class LMS{  
    protected:
        struct Total{
        int Book;
        int Reader;
        int Loan;
        };
        int BookTotal;
        int ReaderTotal;
        int LoanNo;
        Reader *R; //Reader
        Book *B; // Book 
        Loan *L; //Loan
    public:
        //constructor
        LMS();
        //deconstrutor
        ~LMS();
        void InputFromFile(int);
        void OutputToFile(int);
        //book
        void Add(const Book&);
        int IndexOfBook(const string&);
        int IndexOfLoan(const int&);
        bool isBookValid(const string&);
        void PrintBook(int);
        void PrintAllBook();
        //Reader
        void Add(const Reader&);
        void Add(const Loan&);
        void PrintReader(int);
        void PrintAllReader();
        int IndexOfReader(const string&);
        void PrintLoan(int);
        void setAvali(int, bool);
        void setCur(int, bool);
        bool getStatus(int);
        friend Total GetTotal(const LMS&);
        int getCur(int);
        void EditBook(int);
        void EditReader(int);
        void DeleteBook(int);
        void DeleteReader(int);
        //......
        void PrintAllLoan();
        void EditLoan(int);
        void DeleteLoan(int);
        void ReaderStatistics();
        void BookStatistics();
        void returnBook(int);
        int SearchAuthor(string);
        int SearchCate(int);
        void printLoanForm(string, string[], int, time_t);
        void overdueBook();
};