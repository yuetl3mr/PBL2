#include "LMS.h"
LMS Management;

int Last_BookNo, Last_LoanNo, Last_ReaderNo;

void Header();
void MainMenu();
void AddBook();
void AddReader();
void FindBook();
void PrintAllBook();
void PrintAllReader();
void PrintAllLoan();
void EditBooks();
void EditReader();
void EditLoan();
void analyzeData(); 
void analyzeReader();
void ExitNoti();
void AddLoan();
void returnBook();
void SearchAuthor();
void SearchCate();
void overdueBook();

string BookCate[12] = 
        {"Others", "Horror", "Fantasy", "Comics", "Religion", "History", 
        "Romance", "Biography", "Sience", "Computer", "Self-Help", "Novel"};

void ExitNoti(){
    system("cls");
    Header();
    cout << "\t==========================================================================================================\n";
    cout <<"\tCam on ban da su dung chuong trinh\n\t";
    //cout<<"     Chuong trinh se thoat sau " << i << " giay...";
    system("pause");
    system("cls");
    exit(0);
}

void PrintAllBook(){
    Header();
    cout << "\t======================================== Danh sach toan bo sach =========================================\n\n";
    cout << "\tMa so   \tTen sach\t\t\t  Tac Gia\t\t      Danh Muc\t   So luong\n";
    cout << "\t---------------------------------------------------------------------------------------------------------\n";
    Management.PrintAllBook();
    system("pause");
}

void PrintAllReader(){
    Header();
    cout << "\t====================================== Danh sach toan bo doc gia =======================================\n\n";
    cout << "\tMa so   \tHo Va Ten\t   Gioi tinh\t Ngay sinh\tSo Dien Thoai\t   Sach Dang Muon\n";
    cout << "\t---------------------------------------------------------------------------------------------------------\n";
    Management.PrintAllReader();
    system("pause");
}

void PrintAllLoan(){
    Header();
    cout << "\t================================== Danh sach toan giao dich muon sach ===================================\n\n";
    cout << "\tMa so   \tMa Doc Gia\t       Ma Sach\t\t        Ngay Muon\t     Trang Thai\n";
    cout << "\t---------------------------------------------------------------------------------------------------------\n";
    Management.PrintAllLoan();
    system("pause");
}

void Header(){
    system("cls");
    cout << "\t\t\t\t Library Management System - Chuong trinh quan ly thu vien\n";
}

void AddBook(){
    Header();
    cout << "\t========================================== Nhap thong tin sach ==========================================\n";
    cout << "\tNhap so luong sach muon them : ";
    int addTotal;
    while (!(cin >> addTotal) || addTotal < 1){
        cout << "\tSo luong khong hop le, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    for(int index = 0; index < addTotal; index++){
        system("cls");
        Header();
        cout << "\t========================================== Nhap thong tin sach ==========================================\n";
        string tmpBookNo = "BN" + to_string(Last_BookNo + 1);
        Book NewBook(tmpBookNo);
        cout << "\tNhap thong tin sach " << index + 1 << "\n";
        cin >> NewBook;
        Management.Add(NewBook);
        Last_BookNo++;
        cout << "\tNhap thong tin sach " << tmpBookNo << " thanh cong\n\t";
        system("pause");
    }/*for ->so luong, add(newbook)*/
    Management.OutputToFile(1);
    getchar();
    MainMenu();
    return;
}

void AddReader(){
    Header();
    cout << "\t========================================= Nhap thong tin doc gia =========================================\n";
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\tNhap so luong doc gia muon them : ";
    int addTotal;
    while (!(cin >> addTotal) || addTotal < 1){
        cout << "\tSo luong khong hop le, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cin.clear();
    cin.ignore(123, '\n');
    for(int index = 0; index < addTotal; index++){
        Header();
        cout << "\t========================================= Nhap thong tin doc gia =========================================\n";
        string tmpReaderNo = "RD" + to_string(Last_ReaderNo + 1);
        Reader NewReader(tmpReaderNo);
        cout << "\tNhap thong tin doc gia " << index + 1 << "\n";
        cin >> NewReader;
        Management.Add(NewReader);
        cout << "\tNhap thong tin doc gia " << tmpReaderNo << " thanh cong\n\t";
        system("pause");
    }
    Management.OutputToFile(3);
    getchar();
    MainMenu();
    return;
}



void AddLoan(){
    Header();
    cout << "\t======================================== Nhap thong tin muon sach ========================================\n";
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\tNhap ma doc gia : ";
    string ReaderNo;
    while (!(cin >> ReaderNo) || Management.IndexOfReader(ReaderNo) == -1){
        cout << "\tKhong tim thay doc gia, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (Management.getCur(Management.IndexOfReader(ReaderNo)) == 5){
        cout << "\tSo luong sach cua doc gia da dat toi da, vui long tra sach de muon tiep\n\t";
        system("pause");
        getchar();
        MainMenu();
    }
    cout << "\tNhap so luong sach muon : ";
    int addTotal;
    while (!(cin >> addTotal) || addTotal < 1 || addTotal + Management.getCur(Management.IndexOfReader(ReaderNo)) > 5){
        cout << "\tSo luong khong hop le hoac da vuot qua gioi han muon sach, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cin.clear();
    cin.ignore(123, '\n');
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    string book[addTotal];
    int bookindex = 0;
    for(int index = 0; index < addTotal; index++){
        Header();
        cout << "\t======================================== Nhap thong tin muon sach ========================================\n";
        cout << "\tNhap ma sach thu " << index + 1 << " : ";
        string tmpBook;
        while ( !(getline(cin, tmpBook)) || tmpBook == "" || Management.IndexOfBook(tmpBook) == -1 || !Management.isBookValid(tmpBook)){
            cout << "\tKhong tim thay sach hoac sach da duoc muon, vui long nhap lai : ";
        }
        book[bookindex] = tmpBook;
        bookindex++;
        Loan NewLoan(Last_LoanNo + 1, ReaderNo, tmpBook, currentTime, 1);    
        Management.Add(NewLoan);
        Last_LoanNo++;
        Management.setAvali(Management.IndexOfBook(tmpBook), true);
        Management.setCur(Management.IndexOfReader(ReaderNo), true);
        cout << "\tDoc gia " << ReaderNo << " da muon sach " << tmpBook << " thanh cong - " << ctime(&currentTime) << "\t";
        system("pause");
    }
    Management.printLoanForm(ReaderNo, book, bookindex, currentTime);
    // Set trang thai sach muon 
    Management.OutputToFile(1);
    Management.OutputToFile(2);
    Management.OutputToFile(3);
    getchar();
    MainMenu();
    return;
}

void overdueBook(){
    Header();
    cout << "\t============================================ Sach muon qua han =============================================\n";
    Management.overdueBook();
    cout << "\t";
    system("Pause");
    MainMenu();
    return;
}

void Search(){
    Header();
    cout << "\t================================================ Tra cuu =================================================\n";
    cout << "\tHien thi toan bo sach              : Nhan phim 1   ====  Hien thi toan bo doc gia           : Nhan phim 4 \n";
    cout << "\tHien thi toan bo phieu muon        : Nhan phim 2   ====  Tra cuu sach theo tac gia          : Nhan phim 5 \n";
    cout << "\tTra cuu sach theo danh muc         : Nhan phim 3   ====  Tra cuu sach muon qua han          : Nhan phim 6 \n";
    cout << "\t==========================================================================================================\n";
    getchar();
    switch (getchar()){
    case '0':
        getchar();
        MainMenu();
        break;
    case '1':
        PrintAllBook();
        MainMenu();
        break;
    case '2':
        PrintAllLoan();
        MainMenu();
        break;    
    case '3':
        SearchCate();
        MainMenu();
        break;
    case '4':
        PrintAllReader();
        MainMenu();
        break;
    case '5':
        SearchAuthor();
        MainMenu();
        break;
    case '6':
        overdueBook();
        MainMenu();
        break;
    default:
        break;
    }
}

void EditBook(){
    Header();
    cout << "\t=========================================== Sua Thong Tin Sach ==========================================\n";
    cout << "\tNhap ma sach can sua / xoa: ";
    string Bno;
    while ( !(cin >> Bno) || ( Management.IndexOfBook(Bno)) == -1 ){
        cout << "\tKhong tim thay sach, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    Header();
    cout << "\t=========================================== Sua Thong Tin Sach ==========================================\n";
    cout << "\tDang sua thong tin sach\n";
    cout << "\tNhan phim 1 de sua thong tin, nhan phim 2 de xoa : ";
    int tmp = 0;
    while(!(cin >> tmp) || (tmp != 1 && tmp != 2)){
        cout << "\tNhan phim 1 de sua thong tin sach, nhan phim 2 de xoa : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (tmp == 1){
        Management.EditBook(Management.IndexOfBook(Bno));
        cout << "\tSua thong tin sach thanh cong\n\t";
    }else {
        Management.DeleteBook(Management.IndexOfBook(Bno));
        cout << "\tXoa sach thanh cong\n\t";
        Last_BookNo = GetTotal(Management).Book + 1;
        // Xoa ca o bang Loan
    }
    Management.OutputToFile(1);
    system("Pause");
    MainMenu();
    return;
}

void EditReader(){
    Header();
    cout << "\t========================================== Sua Thong Tin Doc Gia =========================================\n";
    cout << "\tNhap ma doc gia can sua / xoa: ";
    string RdNo;
    while ( !(cin >> RdNo) || ( Management.IndexOfReader(RdNo)) == -1 ){
        cout << "\tKhong tim thay doc gia, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    Header();
    cout << "\t========================================== Sua Thong Tin Doc Gia =========================================\n";
    cout << "\tDang sua thong tin doc gia\n";
    cout << "\tNhan phim 1 de sua thong tin, nhan phim 2 de xoa : ";
    int tmp = 0;
    while(!(cin >> tmp) || (tmp != 1 && tmp != 2)){
        cout << "\tNhan phim 1 de sua thong tin sach, nhan phim 2 de xoa : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (tmp == 1){
        cin.clear();
        cin.ignore(123, '\n');
        Management.EditReader(Management.IndexOfReader(RdNo));
        cout << "\tSua thong tin doc gia thanh cong\n\t";
    }else {
        Management.DeleteReader(Management.IndexOfReader(RdNo));
        cout << "\tXoa doc gia thanh cong\n\t";
        Last_ReaderNo = GetTotal(Management).Reader + 1;
        // Xoa ca o bang Loan
    }
    Management.OutputToFile(3);
    system("Pause");
    MainMenu();
    return;
}

void EditLoan(){
    Header();
    cout << "\t========================================= Xoa Thong Tin Muon Sach ========================================\n";
    cout << "\tNhap phieu muon sach can xoa: ";
    int LNo;
    while ( !(cin >> LNo) || ( Management.IndexOfLoan(LNo)) == -1 ){
        cout << "\tKhong tim ma muon, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    Header();
    cout << "\t========================================= Xoa Thong Tin Muon Sach ========================================\n";
        Management.DeleteLoan(Management.IndexOfLoan(LNo));
        cout << "\tXoa phieu muon thanh cong\n\t";
        Last_LoanNo = GetTotal(Management).Loan + 1;
        // Xoa ca o bang Loan
        Management.OutputToFile(2);
    system("Pause");
    MainMenu();
    return;
}

void analyzeReader(){
    Header();
    cout << "\t================================================= Doc Gia =================================================\n";
    Management.ReaderStatistics();
    cout << "\n\t";
    system("pause");
}

void analyzeBook(){
    Header();
    cout << "\t================================================= Sach =================================================\n";
    Management.BookStatistics();
    cout << "\n\t";
    system("pause");
}

void analyzeData(){
    Header();
    cout << "\t================================================ Thong Ke ================================================\n";
    cout << "\tThong ke doc gia                   : Nhan phim 1   ====  Thong ke sach                      : Nhan phim 2 \n";
    cout << "\t                                   Nhan phim 0 de tro ve man hinh                                         \n";
    cout << "\t==========================================================================================================\n";
    getchar();
    switch (getchar()){
    case '0':
        getchar();
        MainMenu();
        break;
    case '1':
        analyzeReader();
        MainMenu();
        break;
    case '2':
        analyzeBook();
        MainMenu();
        break;    
    case '4':
        MainMenu();
        break;
    default:
        MainMenu();
        break;
    }
    
}

void MainMenu(){
    system("cls");
    cout << "\t\t\t\t Library Management System - Chuong trinh quan ly thu vien\n";
    cout << "\t==========================================================================================================\n";
    cout << "\tNhap thong tin sach                : Nhan phim 1   ====  Nhap thong tin doc gia             : Nhan phim 5 \n";
    cout << "\tMuon sach                          : Nhan phim 2   ====  Sua - xoa thong tin doc gia        : Nhan phim 6 \n";
    cout << "\tSua - xoa thong tin sach           : Nhan phim 3   ====  Xoa thong tin muon sach            : Nhan phim 7 \n";
    cout << "\tTra cuu thong tin                  : Nhan phim 4   ====  Thong ke                           : Nhan phim 8 \n";
    cout << "\tTra sach                           : Nhan phim 9   ====  Tro ve man hinh chinh              : Nhan phim 0 \n";
    cout << "\t==========================================================================================================\n";
    switch( getchar() ){
        case '0':
            ExitNoti();
            break;
        case '1':
            AddBook();
            break;
        case '2':
            AddLoan();
            break;
        case '3':
            EditBook();
            break;
        case '4':
            Search();
            break;
        case '5':
            AddReader();
            break;
        case '6':
            EditReader();
            break;
        case '7':
            EditLoan();
            break;
        case '8': 
            analyzeData();
            break;
        case '9':
            returnBook();
            break;
        default:
            MainMenu();
            return;
    }
}

void returnBook(){
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    Header();
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\t================================================ Tra sach ================================================\n";
    cout << "\tNhap ma phieu muon sach : ";
    int LoanNum;
    while ( !(cin >> LoanNum) || Management.IndexOfLoan(LoanNum) == -1 || !Management.getStatus(LoanNum - 1)){
        cout << "\tKhong tim thay giao dich muon sach, vui long nhap lai : ";
    }
    LoanNum--;
    Management.returnBook(LoanNum);
    cout << "\tTra sach thanh cong - " << ctime(&currentTime) << "\t";
    Management.OutputToFile(1);
    Management.OutputToFile(2);
    Management.OutputToFile(3);
    system("Pause");
    MainMenu();
    return;
}

void SearchAuthor(){
    Header();
    cout << "\t========================================== Tim sach theo tac gia ==========================================\n";
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\tNhap ten tac gia can tim : ";
    string author;
    getline(cin, author);
    int num = Management.SearchAuthor(author);
    cout << "\tDa tim thay " << num << " sach cua tac gia " << author << "\n\t";
    system("Pause");
    MainMenu();
    return; 
}

void SearchCate(){
    Header();
    cout << "\t========================================== Tim sach theo danh muc ==========================================\n";
    cin.clear();
    cin.ignore(123, '\n');
    cout << "\tCac danh muc hien co : \n";
    for(int i = 0; i < 12; i++){
        cout << "\t" << i << "." << BookCate[i] << "\n";
    }
    cout << "\tNhap danh muc can tim : ";
    int cate;
    while (!(cin >> cate) || cate > 12 || cate < 0){
        cout << "\tDanh muc khong hop le, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    int num = Management.SearchCate(cate);
    cout << "\tDa tim thay " << num << " sach cua danh muc " << BookCate[cate] << "\n\t";
    system("Pause");
    MainMenu();
    return; 
}

int main(){
    Management.InputFromFile(1); // Nhap file Book
    Management.InputFromFile(2); // Nhap file Reader
    Management.InputFromFile(3); // Nhap file Loan
    Last_BookNo = GetTotal(Management).Book;
    Last_LoanNo = GetTotal(Management).Loan;
    Last_ReaderNo = GetTotal(Management).Reader;
    /*
        Them ham kiem tra tinh lien ket
    */
    MainMenu();
}