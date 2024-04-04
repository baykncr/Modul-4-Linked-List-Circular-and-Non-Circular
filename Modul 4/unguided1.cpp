#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head = NULL;

// Fungsi untuk membuat node baru
Node* buatNode(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    return baru;
}

// Menambahkan node di depan
void tambahDepan(string nama, string nim) {
    Node *baru = buatNode(nama, nim);
    if (head == NULL) {
        head = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Menambahkan node di belakang
void tambahBelakang(string nama, string nim) {
    Node *baru = buatNode(nama, nim);
    if (head == NULL) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

// Menampilkan seluruh data mahasiswa
void tampilData() {
    cout << "DATA MAHASISWA" << endl;
    cout << setw(20) << left << "NAMA" << setw(15) << left << "NIM" << endl;
    Node *temp = head;
    while (temp != NULL) {
        cout << setw(20) << left << temp->nama << setw(15) << left << temp->nim << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string nama, nim;
    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "4. Ubah Depan" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "5. Ubah Belakang" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "6. Ubah Tengah" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "7. Hapus Depan" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "8. Hapus Belakang" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "9. Hapus Tengah" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "10. Hapus List" << endl; // Untuk sederhana, operasi ini tidak diimplementasikan
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "-Tambah Depan-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahDepan(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 2:
                cout << "-Tambah Belakang-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan" << endl;
                break;
            case 11:
                tampilData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
