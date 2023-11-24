#include "LMS.h"
LMS Management;

int Last_BookNo = 0;

void Header();
void MainMenu();
void AddBook();
void AddReader();
void FindBook();
void PrintAllBook();
void PrintAllReader();
void EditBooks();
void EditReader();
void ExitNoti();
void AddLoan();

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
    cout << "\tMa so   \tTen sach\t\t\t  Tac Gia\t\t      Danh Muc\t   Trang thai\n";
    cout << "\t---------------------------------------------------------------------------------------------------------\n";
    Management.PrintAllBook();
    system("pause");
}

void PrintAllReader(){
    Header();
    cout << "\t======================================== Danh sach toan doc gia =========================================\n\n";
    cout << "\tMa so   \tHo Va Ten\t\t    Gioi tinh\t        Ngay sinh\t       So Dien Thoai\n";
    cout << "\t---------------------------------------------------------------------------------------------------------\n";
    Management.PrintAllReader();
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
        string tmpReaderNo = "BN" + to_string(GetTotal(Management).Reader + 1);
        Reader NewReader(tmpReaderNo);
        cout << "\tNhap thong tin doc gia " << index + 1 << "\n";
        cin >> NewReader;
        Management.Add(NewReader);
        cout << "\tNhap thong tin doc gia " << tmpReaderNo << " thanh cong\n\t";
        system("pause");
    }
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
    cout << "\tNhap so luong sach muon : ";
    int addTotal;
    while (!(cin >> addTotal) || addTotal < 1){
        cout << "\tSo luong khong hop le, vui long nhap lai : ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    cin.clear();
    cin.ignore(123, '\n');
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    for(int index = 0; index < addTotal; index++){
        Header();
        cout << "\t======================================== Nhap thong tin muon sach ========================================\n";
        Loan NewLoan(GetTotal(Management).Loan + 1, currentTime);        
        cout << "\tNhap ma sach thu " << index + 1 << " : ";
        string tmpBook;
        while ( !(getline(cin, tmpBook)) || tmpBook == "" || Management.IndexOfBook(tmpBook) == -1 || !Management.isBookValid(tmpBook)){
            cout << "\tKhong tim thay sach hoac sach da duoc muon, vui long nhap lai : ";
        }
        Management.Add(NewLoan);
        cout << "\tDoc gia " << ReaderNo << " da muon sach " << tmpBook << " thanh cong - " << ctime(&currentTime) << "\t";
        system("pause");
    }
    getchar();
    MainMenu();
    return;
}

void Search(){
    Header();
    cout << "\t================================================ Tra cuu =================================================\n";
    cout << "\tHien thi toan bo sach              : Nhan phim 1   ====  Hien thi toan bo doc gia           : Nhan phim 4 \n";
    cout << "\tTra cuu theo trang thai            : Nhan phim 2   ====  Tra cuu theo tac gia               : Nhan phim 5 \n";
    cout << "\tTra cuu theo danh muc              : Nhan phim 3   ====  Tro ve man hinh chinh              : Nhan phim 0 \n";
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
    case '4':
        PrintAllReader();
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
    Management.PrintBook(Management.IndexOfBook(Bno));
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
        Last_BookNo = GetTotal(Management).Book + 1;
        // Xoa ca o bang Loan
    }
    system("Pause");
    MainMenu();
    return;
}

void MainMenu(){
    system("cls");
    cout << "\t\t\t\t Library Management System - Chuong trinh quan ly thu vien\n";
    cout << "\t==========================================================================================================\n";
    cout << "\tNhap thong tin sach                : Nhan phim 1   ====  Nhap thong tin doc gia             : Nhan phim 5 \n";
    cout << "\tNhap thong tin muon sach           : Nhan phim 2   ====  Sua - xoa thong tin doc gia        : Nhan phim 6 \n";
    cout << "\tSua - xoa thong tin sach           : Nhan phim 3   ====  Sua - xoa thong tin muon sach      : Nhan phim 7 \n";
    cout << "\tTra cuu thong tin                  : Nhan phim 4   ====  Thong ke                           : Nhan phim 8 \n";
    cout << "\t                                   Nhan phim 0 de thoat chuong trinh                                      \n";
    cout << "\t==========================================================================================================\n";
    // Them Thong Ke Sach, doc gia, ....
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
        default:
            MainMenu();
            return;
    }
}

int main(){
    Management.InputFromFile(1); // Nhap file Book
    Management.InputFromFile(2); // Nhap file Reader
    Management.InputFromFile(3); // Nhap file Loan
    Last_BookNo = GetTotal(Management).Book;
    /*
        Them ham kiem tra tinh lien ket
    */
    MainMenu();
}