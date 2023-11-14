#include "Book.h"
#include "Reader.h"
#include "Loan.h"

struct Total{
    int Book;
    int Reader;
    int Loan;
};

class LMS{
    private:
        /*
        Thong tin admin
        */
        // 
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
        int IndexOf(const string&);
        void PrintBook();
        //Reader
        void Add(const Reader&);
        void Add(const Loan&);
        void PrintReader();
        int IndexOf(const Reader&);
        void PrintLoan();
        friend Total GetTotal(const LMS&);
        void EditBook(int);
        //......
};