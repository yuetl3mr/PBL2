#include "Loan.h"

Loan::Loan()
    : LoanNo(0), BookNo("NULL"), ReaderNo("NULL"), LoanDay(time(0)), Status(1)
{
}

Loan::Loan(int no, string cno, string bno, time_t day, bool stt)
    : LoanNo(no), BookNo(bno), ReaderNo(cno), LoanDay(day), Status(stt)
{
}

Loan::Loan(int no, time_t time)
    : LoanNo(no), LoanDay(time)
{}

Loan::~Loan()
{
}

istream& operator>>(istream& inp, Loan& Info){
    Info.LoanNo ++;
    Info.LoanDay = time(0);
    cout << "Nhap ma so sach muon : "; inp >> Info.BookNo;
    // check tinh hop le
    return inp;
}

const ostream& operator<<(ostream& outp, const Loan& Info){
    tm* Time = localtime(&Info.LoanDay);
    cout << "\t"; outp << Info.LoanNo <<"\t   ";
    cout << "\t"; outp << setw(17) << left << Info.ReaderNo;
    cout << "\t"; outp << setw(17) << left << Info.BookNo;
    cout << "\t"; outp << Time->tm_mday; cout <<"/";
    outp << 1 + Time->tm_mon; cout <<"/";
    outp << 1900 + Time->tm_year; 
    cout << setw(10) << left << "";
    cout << "\t"; outp << Info.Status; //note
    cout << endl;
    return outp;
}

int LoanInfo(const Loan& L){
    return L.LoanNo;
}

string Loan::printFile(){
    return to_string(LoanNo) + ";" + ReaderNo + ";" + BookNo + ";" + to_string(LoanDay) + ";" + to_string(Status);
}

string Loan::getBook(){
    return BookNo;
}

string Loan::getReader(){
    return ReaderNo;
}

void Loan::setStatus(){
    Status = false;
}

bool Loan::getStatus(){
    return Status;
}

void Loan::isoverDue(){
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    double seconds = abs(difftime(LoanDay, currentTime));
    int days = static_cast<int>(seconds / (60 * 60 * 24));
    if (days > 60){
        cout << "\t"; cout << "Ma phieu muon : " << LoanNo << "\n";
        cout << "\t"; cout << "Ma doc gia : " << ReaderNo << "\n";
        cout << "\t"; cout << "Ma sach : " << BookNo << "\n";
        cout << "\tSo ngay qua han : "; cout << days;
        cout << endl;
        cout << "\t======================\n";
    }
}