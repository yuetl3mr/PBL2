#include <bits/stdc++.h>
using namespace std;

class Reader{
    private:
        string ReaderNo; 
        bool Gender;
        string Name;
        time_t DoB;
        string Tel; 
        bool Cur;
    public:
        //constructor
        Reader();
        Reader(string);
        Reader(string, bool, string, time_t, string, bool);
        //deconstructor
        ~Reader();
        //overload operator 
        friend istream& operator>>(istream&, Reader&);
        friend const ostream& operator<<(ostream&, const Reader&);
        friend const string& ReaderInfo(const Reader&);
        int GetCur();
        void SetCur();
        bool GetGender();
        string printFile();
};