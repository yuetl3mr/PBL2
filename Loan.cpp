#include "Loan.h"

Loan::Loan()
    : LoanNo(0), BookNo("NULL"), CustomerNo("NULL"), LoanDay(time(0))
{
}

Loan::Loan(int no, string bno, string cno, time_t day)
    : LoanNo(no), BookNo(bno), CustomerNo(cno), LoanDay(day)
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
    cout << "Ma muon sach = "; outp << Info.LoanNo;
    cout << "\nMa so nguoi muon = "; outp << Info.CustomerNo;
    cout << "\nMa so sach muon = "; outp << Info.BookNo;
    cout << "\nNgay muon = "; 
    outp << Time->tm_mday; cout <<"/";
    outp << 1 + Time->tm_mon; cout <<"/";
    outp << 1900 + Time->tm_year; 
    cout << endl << endl;
    return outp;
}
//Note : tinh thoi gian den han tra sach = giay -> time(0) - LoanTime
//Update status (Book, Customer)
