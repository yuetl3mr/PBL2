#include "LMS.h"

string BC[12] = 
        {"Others", "Horror", "Fantasy", "Comics", "Religion", "History", 
        "Romance", "Biography", "Sience", "Computer", "Self-Help", "Novel"};

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
        bool Cur;
        while(getline(fp, INPUT)){
            istringstream iss(INPUT);
            getline(iss, ReaderNo, ';');
            string tempGender, tempDoB, tempCur;
            getline(iss, tempGender, ';');
            Gender = (tempGender == "1");
            getline(iss, Name, ';');
            getline(iss, tempDoB, ';');
            DoB = std::stol(tempDoB);
            getline(iss, Tel, ';');
            getline(iss, tempCur, ';');
            Cur = (tempCur == "0") ? true : false;
            Reader NewReader(ReaderNo, Gender, Name, DoB, Tel, Cur);
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
            Loan NewLoan(LoanNo, ReaderNo, BookNo, LoanDay, true);
            //sua lai, add them trang thai
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

int LMS::IndexOfLoan(const int& tmpL){
    for(int i = 0; i < this->LoanNo; i++){
        if (LoanInfo(L[i]) == tmpL)  
            return i;
    }
    return -1;
}

void LMS::PrintBook(int index){
        cout << B[index];
}

void LMS::PrintAllBook(){
    for(int i = 0; i < BookTotal; i++){
        PrintBook(i);
    }
}

void LMS::PrintReader(int index){
        cout << R[index];
}

void LMS::PrintLoan(int index){
        cout << L[index];
}

LMS::Total GetTotal(const LMS& tmp){
    return {tmp.BookTotal, tmp.ReaderTotal, tmp.LoanNo};
}

bool LMS::isBookValid(const string& BookNo){
    for(int i = 0; i < this->BookTotal; i++){
        if (BookInfo(B[i]) == BookNo){
            if ((B[i]).getAvali() > 0){
                return 1;
            }
        }  
    }
    return 0;
}

void LMS::EditBook(int index){
    cin >> B[index];
}

void LMS::EditReader(int index){
    cin >> R[index];
}

void LMS::EditLoan(int index){
    cin >> L[index];
}

void LMS::DeleteBook(int index){
    for (int i = index; i < this->BookTotal - 1; i++) {
        this->B[i] = this->B[i + 1];
    }
    --this->BookTotal;
}

void LMS::DeleteLoan(int index){
    for (int i = index; i < this->LoanNo - 1; i++) {
        this->L[i] = this->L[i + 1];
    }
    --this->BookTotal;
}

void LMS::DeleteReader(int index){
    for (int i = index; i < this->ReaderTotal - 1; i++) {
        this->R[i] = this->R[i + 1];
    }
    --this->ReaderTotal;
}

void LMS::PrintAllReader(){
    for(int i = 0; i < ReaderTotal; i++){
        PrintReader(i);
    }
}

void LMS::PrintAllLoan(){
    for(int i = 0; i < LoanNo; i++){
        PrintLoan(i);
    }
}

void LMS::ReaderStatistics(){
        int totalReaders = ReaderTotal;
        int maleReaders = 0, femaleReaders = 0;
        int borrowers = 0, totalLoans = 0;
        for (int i = 0; i < ReaderTotal; ++i) {
            if (R[i].GetGender()) {
                maleReaders++;
            } else {
                femaleReaders++;
            }
            if (R[i].GetCur()) {
                borrowers++;
            }
        }
        double malePercentage = static_cast<double>(maleReaders) / totalReaders * 100.0;
        double femalePercentage = static_cast<double>(femaleReaders) / totalReaders * 100.0;
        double borrowingRate = (totalReaders > 0) ? static_cast<double>(borrowers) / ReaderTotal * 100.0 : 0;
        cout << "\tTi le doc gia nam : " << fixed << setprecision(4) << malePercentage << "%" << endl;
        cout << "\tTi le doc gia nu : " << fixed << setprecision(4) << femalePercentage << "%" << endl;
        cout << "\tTi le doc gia dang muon sach : " << setprecision(4) << borrowingRate << "%" << endl;
        cout << "\tTi le doc gia khong muon sach :" << 100.0 - borrowingRate << "%" << endl;
        cout << "\tTong so nguoi dang muon sach: " << borrowers;

}

void LMS::BookStatistics(){
    int available, unavailable;
    int Count[12];    
    for(int index = 0 ; index < 12; index ++){
        Count[index] = 0;
    }
    for (int index = 0; index < BookTotal; index ++){
        available += B[index].getAvali();
        unavailable += B[index].getTotal() - B[index].getAvali();
        if (B[index].GetCategory() > 0 && B[index].GetCategory() < 12){
            Count[B[index].GetCategory()]++; 
        }
    }
    double AP = (BookTotal > 0) ? static_cast<double>(available) / BookTotal * 100.0 : 0;
    cout << "\tTong so sach co san : " << available << endl;
    cout << "\tTong so dang duoc muon : " << unavailable << endl;
    cout << "\tTi le sach co san : " << fixed << setprecision(4) << AP << "%" << endl;
    cout << "\tTi le sach dang duoc muon : " << fixed << setprecision(4) << 100.0 - AP << "%" << endl;
    cout << "\tTi le sach thuoc tung danh muc : \n";
    for(int index = 0; index < 12; index ++){
        cout << "\t" << BC[index] << " : ";
        cout << fixed << setprecision(4) << static_cast<double>(Count[index]) / BookTotal * 100.0 << "%" << endl;
    }
}

void LMS::OutputToFile(int T){
    if (T == 1){
        string FileName = "Book.txt";
        ofstream fp(FileName);
        if(!fp.is_open()){
        cout << "     File " << FileName << " khong ton tai\n";
    }
        for(int index = 0; index < BookTotal; index ++){
            fp << B[index].printFile() << endl;
        }
        fp.close();
    }else if (T == 2){
        string FileName = "Loan.txt";
        ofstream fp(FileName);
        if(!fp.is_open()){
        cout << "     File " << FileName << " khong ton tai\n";
        }
        for(int index = 0; index < LoanNo; index ++){
            fp << L[index].printFile() << endl;
        }
        fp.close();
    }else{
        // input Reader
        string FileName = "Reader.txt";
        ofstream fp(FileName);
        if(!fp.is_open()){
        cout << "     File " << FileName << " khong ton tai\n";
        }
        for(int index = 0; index < ReaderTotal; index ++){
            fp << R[index].printFile() << endl;
        }
        fp.close();
    }
}

void LMS::setAvali(int index){
    B[index].setAvali(true);
}

void LMS::setCur(int index){
    R[index].SetCur();
}