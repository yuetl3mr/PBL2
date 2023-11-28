#include <bits/stdc++.h>
using namespace std;

class Loan
{
protected:
    int LoanNo;
    string ReaderNo;
    string BookNo;
    time_t LoanDay;
    bool Status;
public:
    Loan();
    Loan(int, string, string, time_t, bool);
    Loan(int, time_t);
    ~Loan();
    friend int LoanInfo(const Loan&);
    friend istream& operator>>(istream&, Loan&);
    friend const ostream& operator<<(ostream&, const Loan&);
    string printFile();
};

class LoanGroup : public Loan{
    private:
    int Total;
};


