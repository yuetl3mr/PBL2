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
        //Reader
        void Add(const Reader&);
        void Add(const Loan&);
        void PrintReader(int);
        void PrintAllReader();
        int IndexOfReader(const string&);
        void PrintLoan();
        friend Total GetTotal(const LMS&);
        void EditBook(int);
        void EditReader(int);
        void DeleteBook(int);
        void DeleteReader(int);
        //......
        string BookNo(int);
};