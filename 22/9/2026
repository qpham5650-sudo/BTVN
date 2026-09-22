#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maSV;
    string tenSV;
    string lop;
    float tongKet;
    string hanhKiem;
};

struct Node {
    SinhVien data;
    Node* left;
    Node* right;
};

Node* khoiTaoCay() {
    return nullptr;
}

Node* taoNode(SinhVien sv) {
    Node* node = new Node;
    node->data = sv;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* chenNode(Node* root, SinhVien sv) {
    if (root == nullptr) return taoNode(sv);
    if (sv.maSV < root->data.maSV)
        root->left = chenNode(root->left, sv);
    else if (sv.maSV > root->data.maSV)
        root->right = chenNode(root->right, sv);
    return root;
}

Node* timKiem(Node* root, int maSV) {
    if (root == nullptr || root->data.maSV == maSV) return root;
    if (maSV < root->data.maSV) return timKiem(root->left, maSV);
    return timKiem(root->right, maSV);
}

void duyetCay(Node* root) {
    if (root != nullptr) {
        duyetCay(root->left);
        cout << "Ma SV: " << root->data.maSV
             << ", Ten: " << root->data.tenSV
             << ", Lop: " << root->data.lop
             << ", Tong ket: " << root->data.tongKet
             << ", Hanh kiem: " << root->data.hanhKiem << endl;
        duyetCay(root->right);
    }
}

SinhVien nhapSinhVien() {
    SinhVien sv;
    cout << "Nhap ma SV: "; cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap ten SV: "; getline(cin, sv.tenSV);
    cout << "Nhap lop: "; getline(cin, sv.lop);
    cout << "Nhap tong ket: "; cin >> sv.tongKet;
    cin.ignore();
    cout << "Nhap hanh kiem (Tot/Kha/Trung binh/Yeu): ";
    getline(cin, sv.hanhKiem);
    return sv;
}

int main() {
    Node* root = khoiTaoCay();
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        SinhVien sv = nhapSinhVien();
        root = chenNode(root, sv);
    }

    cout << "\nDanh sach sinh vien trong cay (duyet In-order):\n";
    duyetCay(root);

    int maTim;
    cout << "\nNhap ma sinh vien can tim: ";
    cin >> maTim;

    Node* ketQua = timKiem(root, maTim);
    if (ketQua != nullptr) {
        cout << "Thong tin sinh vien tim thay:\n";
        cout << "Ma SV: " << ketQua->data.maSV
             << ", Ten: " << ketQua->data.tenSV
             << ", Lop: " << ketQua->data.lop
             << ", Tong ket: " << ketQua->data.tongKet
             << ", Hanh kiem: " << ketQua->data.hanhKiem << endl;
    } else {
        cout << "Khong co sinh vien trong cay voi ma so nay.\n";
    }

    return 0;
}

