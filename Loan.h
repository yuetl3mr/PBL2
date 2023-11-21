#include <bits/stdc++.h>
using namespace std;

class Loan
{
protected:
    int LoanNo;
    string CustomerNo;
    string BookNo;
    time_t LoanDay;
public:
    Loan();
    Loan(int, string, string, time_t);
    Loan(int, time_t);
    ~Loan();
    friend istream& operator>>(istream&, Loan&);
    friend const ostream& operator<<(ostream&, const Loan&);
};

