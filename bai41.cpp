// File: bai41.cpp
#include <iostream>
#include <string>
using namespace std;

struct HangHoa {
    int maHH;
    string tenHH;
    string ngayXuat;
    float gia;
    HangHoa* left;
    HangHoa* right;
};

HangHoa* taoNode(int maHH, string tenHH, string ngayXuat, float gia) {
    HangHoa* node = new HangHoa{maHH, tenHH, ngayXuat, gia, nullptr, nullptr};
    return node;
}

HangHoa* chenNode(HangHoa* root, HangHoa* node) {
    if (!root) return node;
    if (node->maHH < root->maHH) root->left = chenNode(root->left, node);
    else root->right = chenNode(root->right, node);
    return root;
}

void duyetCay(HangHoa* root) {
    if (!root) return;
    duyetCay(root->left);
    cout << "MaHH: " << root->maHH << ", TenHH: " << root->tenHH
         << ", NgayXuat: " << root->ngayXuat << ", Gia: " << root->gia << endl;
    duyetCay(root->right);
}

HangHoa* timKiem(HangHoa* root, int maHH) {
    if (!root) return nullptr;
    if (root->maHH == maHH) return root;
    if (maHH < root->maHH) return timKiem(root->left, maHH);
    else return timKiem(root->right, maHH);
}

int main() {
    HangHoa* root = nullptr;
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        int ma; string ten, ngay; float gia;
        cout << "Nhap MaHH, TenHH, NgayXuat, Gia: ";
        cin >> ma; cin.ignore();
        getline(cin, ten);
        getline(cin, ngay);
        cin >> gia; cin.ignore();
        HangHoa* node = taoNode(ma, ten, ngay, gia);
        root = chenNode(root, node);
    }

    cout << "\nDanh sach hang hoa:\n";
    duyetCay(root);

    int maTim;
    cout << "\nNhap MaHH can tim: ";
    cin >> maTim;
    HangHoa* hh = timKiem(root, maTim);
    if (hh) {
        cout << "Tim thay: " << hh->tenHH << ", NgayXuat: " << hh->ngayXuat << ", Gia: " << hh->gia << endl;
    } else {
        cout << "Khong co hang hoa trong cay.\n";
    }

    return 0;
}

