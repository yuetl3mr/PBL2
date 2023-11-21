#include "LMS.h"


LMS::LMS()
    : BookTotal(0), ReaderTotal(0), LoanNo(0)
{
    this->B = NULL;
    this->R = NULL;
    this->L = NULL;
}

LMS::~LMS(){
    delete[] this->B;
    delete[] this->R;
    delete[] this->L;  
}

void LMS::Add(const Book& NewBook){
    if (this->BookTotal == 0){
        this->B = new Book[this->BookTotal + 1];
        *(this->B + this->BookTotal) = NewBook;
    }else {
        Book *temp = new Book[this->BookTotal]; 
        for(int i = 0; i < this->BookTotal; i++){
            *(temp + i) = *(this->B + i);
        }
        delete [] this->B;
        this->B = new Book[this->BookTotal + 1];
        for(int i = 0; i < this->BookTotal; i++){
            *(this->B + i) = *(temp + i);
        }
        *(this->B + this->BookTotal) = NewBook;
    }
    ++this->BookTotal;
}

void LMS::Add(const Reader& NewReader){
    if (this->ReaderTotal == 0){
        this->R = new Reader[this->ReaderTotal + 1];
        *(this->R + this->ReaderTotal) = NewReader;
    }else {
        Reader *temp = new Reader[this->ReaderTotal];
        for(int i = 0; i < this->ReaderTotal; i++){
            *(temp + i) = *(this->R + i);
        }
        delete [] this->R;
        this->R = new Reader[this->ReaderTotal + 1];
        for(int i = 0; i < this->ReaderTotal; i++){
            *(this->R + i) = *(temp + i);
        }
        *(this->R + this->ReaderTotal) = NewReader;
    }
    ++this->ReaderTotal;
}

void LMS::Add(const Loan& NewLoan){
    if (this->LoanNo == 0){
        this->L = new Loan[this->LoanNo + 1];
        *(this->L + this->LoanNo) = NewLoan;
    }else {
        Loan *temp = new Loan[this->LoanNo]; 
        for(int i = 0; i < this->LoanNo; i++){
            *(temp + i) = *(this->L + i);
        }
        delete [] this->L;
        this->L = new Loan[this->LoanNo + 1];
        for(int i = 0; i < this->LoanNo; i++){
            *(this->L + i) = *(temp + i);
        }
        *(this->L + this->LoanNo) = NewLoan;
    }
    ++this->LoanNo;
}

void LMS::InputFromFile(int T){
    string FileName;
    if (T == 1){
        // input book
        FileName = "Book.txt";
        ifstream fp(FileName);
        if(!fp.is_open()){
            cout << "     File " << FileName << " khong ton tai\n";
        }
        string INPUT;
        string BookNo, Title, Author;
        int Category;
        bool Status;
        while(getline(fp, INPUT)){
            istringstream iss(INPUT);
            getline(iss, BookNo, ';');
            getline(iss, Title, ';');
            getline(iss, Author, ';');
            string tempCategory, tempStatus;
            getline(iss, tempCategory, ';');
            Category = stoi(tempCategory);
            getline(iss, tempStatus, ';');  
            Status = (tempStatus == "1");
            Book InBook(BookNo, Title, Author, Category, Status);
            Add(InBook);
        }
    }else if (T == 2){
        // input Reader
        FileName = "Reader.txt";
        ifstream fp(FileName);
        if(!fp.is_open()){
            cout << "     File " << FileName << " khong ton tai\n";
        }
        string INPUT;
        string ReaderNo; 
        bool Gender;
        string Name;
        time_t DoB;
        string Tel;
        bool LoanStatus;
        while(getline(fp, INPUT)){
            istringstream iss(INPUT);
            getline(iss, ReaderNo, ';');
            string tempGender, tempDoB, tempLoanStatus;
            getline(iss, tempGender, ';');
            Gender = (tempGender == "1");
            getline(iss, Name, ';');
            getline(iss, tempDoB, ';');
            DoB = std::stol(tempDoB);
            getline(iss, Tel, ';');
            getline(iss, tempLoanStatus, ';');
            LoanStatus = (tempLoanStatus == "1");
            Reader NewReader(ReaderNo, Gender, Name, DoB, Tel, LoanStatus);
            Add(NewReader);
        }
    }else{
        // input Loan
        FileName = "Loan.txt";
        ifstream fp(FileName);
        if(!fp.is_open()){
            cout << "     File " << FileName << " khong ton tai\n";
        }
        string INPUT;
        int LoanNo;
        string ReaderNo, BookNo;
        time_t LoanDay;
        bool LoanStatus;
        while(getline(fp, INPUT)){
            istringstream iss(INPUT);
            string tempLoanNo, tempLoanDay;
            getline(iss, tempLoanNo, ';');
            LoanNo = stoi(tempLoanNo);
            getline(iss, ReaderNo, ';');
            getline(iss, BookNo, ';');
            getline(iss, tempLoanDay, ';');
            LoanDay = stol(tempLoanDay);
            Loan NewLoan(LoanNo, ReaderNo, BookNo, LoanDay);
            Add(NewLoan);
        }
    }
}

int LMS::IndexOfBook(const string& BookNo){
    for(int i = 0; i < this->BookTotal; i++){
        if (BookInfo(B[i]) == BookNo)  
            return i;
    }
    return -1;
}

int LMS::IndexOfReader(const string& ReaderNo){
    for(int i = 0; i < this->ReaderTotal; i++){
        if (ReaderInfo(R[i]) == ReaderNo)  
            return i;
    }
    return -1;
}

void LMS::PrintBook(){
    for(int i = 0; i < BookTotal; i++){
        cout << B[i];
    }
}

void LMS::PrintReader(){
    for(int i = 0; i < ReaderTotal; i++){
        cout << R[i];
    }
}

void LMS::PrintLoan(){
    for(int i = 0; i < LoanNo; i++){
        cout << L[i];
    }
}

Total GetTotal(const LMS& tmp){
    return {tmp.BookTotal, tmp.ReaderTotal, tmp.LoanNo};
}

bool LMS::isBookValid(const string& BookNo){
    for(int i = 0; i < this->BookTotal; i++){
        if (BookInfo(B[i]) == BookNo){
            if (bookStatus(B[i])){
                return 1;
            }
        }  
    }
    return 0;
}

void LMS::EditBook(int index){
    cin >> B[index];
}