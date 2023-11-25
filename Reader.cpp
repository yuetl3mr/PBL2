#include "Reader.h"

Reader::Reader()
    : ReaderNo("NULL"), Name("NULL"), Gender(NULL), Tel("NULL"), Cur(0)
{
}

Reader::Reader(string rn)
    : ReaderNo(rn), Name("NULL"), Gender(NULL), Tel("NULL")
{
}

Reader::Reader(string no, bool gender, string name, time_t dob, string tel, bool cb)
    : ReaderNo(no), Name(name), Gender(gender), Tel(tel), DoB(dob), Cur(cb)
{
}
//note
Reader::~Reader()
{
}

istream& operator>>(istream& inp, Reader& NewReader){
    std::tm timeInfo = {};
    int day, month, year;   
    string tmp = "";
    cout << "\t------------------------\n";
    cout << "\tHo va ten : "; 
    while ( !(getline(inp, NewReader.Name)) || NewReader.Name == ""){
        cout << "\tTen khong duoc de trong, vui long nhap lai : ";
    }
    cout << "\tNgay sinh (dd mm yyyy): ";
    inp >> day >> month >> year;
    timeInfo.tm_year = year - 1900; 
    timeInfo.tm_mon = month - 1;
    timeInfo.tm_mday = day;
    NewReader.DoB = std::mktime(&timeInfo);
    cout << "\tGioi tinh (0 hoac 1) : "; 
    while (!(inp >> NewReader.Gender) || NewReader.Gender != 1 && NewReader.Gender != 0){
        cout << "\tGioi tinh khong hop le, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\tSo dien thoai : ";
    while ( !(getline(inp, NewReader.Tel)) || NewReader.Tel == ""){
        cout << "\tSo dien thoai khong duoc de trong, vui long nhap lai : ";
    }
    return inp;
}

const ostream& operator<<(ostream& outp, const Reader& Reader){
    tm* Time = localtime(&Reader.DoB);
    cout << "\t"; outp << Reader.ReaderNo <<"\t";
    cout << "\t"; outp << setw(20) << left << Reader.Name; 
    cout << "\t"; outp << setw(7) << left << Reader.Gender;
    cout << "\t"; outp << Time->tm_mday; cout <<"/";
    outp << 1 + Time->tm_mon; cout <<"/";
    outp << 1900 + Time->tm_year; 
    cout << setw(5) << left << "";
    cout << "\t"; outp << setw(20) << left <<  Reader.Tel; //note
    cout << "\t"; outp << Reader.Cur;
    cout << endl;
    return outp;
}

const string& ReaderInfo(const Reader& R){
    return R.ReaderNo;
}

int Reader::GetCur(){
    return Cur;
}

bool Reader::GetGender(){
    return Gender;
}

string Reader::printFile(){
    return ReaderNo + ";" + to_string(Gender) + ";" + Name + ";" + to_string(DoB) + ";" + Tel + ";" + to_string(Cur);    
}

void Reader::SetCur(){
    Cur = true;
}