#include "Reader.h"

Reader::Reader()
    : ReaderNo("NULL"), Name("NULL"), Gender(NULL), Tel("NULL")
{
}

Reader::Reader(string rn)
    : ReaderNo(rn), Name("NULL"), Gender(NULL), Tel("NULL")
{
}

Reader::Reader(string no, bool gender, string name, time_t dob, string tel, bool borrowstatus)
    : ReaderNo(no), Name(name), Gender(gender), Tel(tel), DoB(dob)
{
}

Reader::~Reader()
{
}

istream& operator>>(istream& inp, Reader& NewReader){
    string tmp = "";
    cout << "\t------------------------\n";
    cout << "\tHo va ten : "; 
    while ( !(getline(inp, NewReader.Name)) || NewReader.Name == ""){
        cout << "\tTen khong duoc de trong, vui long nhap lai : ";
    }
    // cout << "\tNam sinh : ";
    // while ((!getline(inp, tmp) || tmp == "") && stoi(tmp) ){
        
    // }
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
    cout << "Ma so nguoi dung = "; outp << Reader.ReaderNo;
    cout << "\nHo va ten = "; outp << Reader.Name;
    cout << "\nNgay sinh = ";
    outp << Time->tm_mday; cout <<"/";
    outp << 1 + Time->tm_mon; cout <<"/";
    outp << 1900 + Time->tm_year; 
    cout << "\nGioi tinh = "; outp << Reader.Gender;
    cout << "\nSo dien thoai = "; outp << Reader.Tel;
    cout << endl << endl;
    return outp;
}

const string& ReaderInfo(const Reader& R){
    return R.ReaderNo;
}
