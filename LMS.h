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
        //book
        void Add(const Book&);
        int IndexOfBook(const string&);
        bool isBookValid(const string&);
        void PrintBook(int);
        void PrintAllBook();
        string GetBookNo(int);
        //Reader
        void Add(const Reader&);
        void Add(const Loan&);
        void PrintReader();
        int IndexOfReader(const string&);
        void PrintLoan();
        friend Total GetTotal(const LMS&);
        void EditBook(int);
        void DeleteBook(int);
        //......
};