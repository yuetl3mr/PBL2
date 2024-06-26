#include <bits/stdc++.h>
using namespace std;

class Reader{
    private:
        string ReaderNo; 
        bool Gender;
        string Name;
        time_t DoB;
        string Tel; 
        int Cur;
        // int Cur -> so sach dang muon -> quan ly
    public:
        //constructor
        Reader();
        Reader(string);
        Reader(string, bool, string, time_t, string, int);
        //deconstructor
        ~Reader();
        //overload operator 
        friend istream& operator>>(istream&, Reader&);
        friend const ostream& operator<<(ostream&, const Reader&);
        friend const string& ReaderInfo(const Reader&);
        int GetCur();
        void SetCur(bool);
        bool GetGender();
        string printFile();
        string getName();
};