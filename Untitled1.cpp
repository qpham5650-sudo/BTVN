#include <iostream>
#include <string>
using namespace std;

// Câu 1: Ð?nh nghia c?u trúc hàng hóa
struct Date {
    int day, month, year;
};

struct HangHoa {
    string maHang;
    string tenHang;
    Date ngayXuat;
    double giaXuat; // tri?u d?ng
};

// Câu 2: Hàm nh?p m?ng hàng hóa
void nhapHangHoa(HangHoa ds[], int &n) {
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    cin.ignore(); // b? ký t? xu?ng dòng

    for (int i = 0; i < n; i++) {
        cout << "\nNhap hang hoa thu " << i + 1 << ":\n";
        cout << "Ma hang: ";
        getline(cin, ds[i].maHang);
        cout << "Ten hang: ";
        getline(cin, ds[i].tenHang);
        cout << "Ngay xuat (dd mm yyyy): ";
        cin >> ds[i].ngayXuat.day >> ds[i].ngayXuat.month >> ds[i].ngayXuat.year;
        cout << "Gia xuat (trieu dong): ";
        cin >> ds[i].giaXuat;
        cin.ignore();
    }
}

// Câu 3: Hàm xu?t m?ng hàng hóa
void xuatHangHoa(HangHoa ds[], int n) {
    cout << "\nDanh sach hang hoa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma: " << ds[i].maHang
             << " | Ten: " << ds[i].tenHang
             << " | Ngay xuat: " << ds[i].ngayXuat.day << "/" 
             << ds[i].ngayXuat.month << "/" << ds[i].ngayXuat.year
             << " | Gia: " << ds[i].giaXuat << " trieu\n";
    }
}

// Câu 4: S?p x?p ch?n tr?c ti?p theo giá tang d?n
void selectionSort(HangHoa ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].giaXuat < ds[minIndex].giaXuat) {
                minIndex = j;
            }
        }
        // Hoán d?i
        HangHoa temp = ds[i];
        ds[i] = ds[minIndex];
        ds[minIndex] = temp;
    }
}

// Câu 5: Tìm ki?m nh? phân theo giá
void timKiemGia(HangHoa ds[], int n, double X) {
    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (ds[mid].giaXuat == X) {
            cout << "\nTim thay hang hoa co gia " << X << " trieu:\n";
            cout << "Ma: " << ds[mid].maHang
                 << " | Ten: " << ds[mid].tenHang
                 << " | Ngay xuat: " << ds[mid].ngayXuat.day << "/" 
                 << ds[mid].ngayXuat.month << "/" << ds[mid].ngayXuat.year
                 << " | Gia: " << ds[mid].giaXuat << " trieu\n";
            found = true;
            break;
        } else if (ds[mid].giaXuat < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "\nKhong tim thay hang hoa co gia " << X << " trieu.\n";
    }
}

// Câu 6: Hàm chính
int main() {
    HangHoa ds[100];
    int n;
    nhapHangHoa(ds, n);
    xuatHangHoa(ds, n);

    selectionSort(ds, n);
    cout << "\nDanh sach sau khi sap xep tang dan theo gia:\n";
    xuatHangHoa(ds, n);

    double X;
    cout << "\nNhap gia can tim: ";
    cin >> X;
    timKiemGia(ds, n, X);

    return 0;
}

