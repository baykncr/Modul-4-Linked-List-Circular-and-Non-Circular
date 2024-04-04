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

// Tambahkan node di tengah setelah node tertentu
void tambahTengah(string nama, string nim, string posisi_setelah) {
    Node *baru = buatNode(nama, nim);
    Node *temp = head;
    while (temp != NULL && temp->nama != posisi_setelah) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node dengan nama " << posisi_setelah << " tidak ditemukan!" << endl;
    } else {
        baru->next = temp->next;
        temp->next = baru;
        cout << "Data telah ditambahkan setelah " << posisi_setelah << endl;
    }
}

// Hapus node dengan nama tertentu
void hapusNode(string nama) {
    if (head == NULL) {
        cout << "Linked list kosong!" << endl;
        return;
    }
    Node *temp = head;
    Node *sebelum = NULL;
    while (temp != NULL && temp->nama != nama) {
        sebelum = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node dengan nama " << nama << " tidak ditemukan!" << endl;
    } else {
        if (sebelum == NULL) {
            head = temp->next;
        } else {
            sebelum->next = temp->next;
        }
        delete temp;
        cout << "Data dengan nama " << nama << " berhasil dihapus!" << endl;
    }
}

// Ubah data node dengan nama tertentu
void ubahData(string nama, string nim) {
    Node *temp = head;
    while (temp != NULL && temp->nama != nama) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node dengan nama " << nama << " tidak ditemukan!" << endl;
    } else {
        temp->nim = nim;
        cout << "Data dengan nama " << nama << " berhasil diubah!" << endl;
    }
}

// Hapus seluruh data
void hapusList() {
    while (head != NULL) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "Seluruh data berhasil dihapus!" << endl;
}

int main() {
    // Menambahkan data awal
    tambahBelakang("Jawad", "23300001");
    tambahBelakang("Farrel", "23300003");
    tambahBelakang("Denis", "23300005");
    tambahBelakang("Anis", "23300008");
    tambahBelakang("Bowo", "23300015");
    tambahBelakang("Gahar", "23300040");
    tambahBelakang("Udin", "23300048");
    tambahBelakang("Ucok", "23300050");
    tambahBelakang("Budi", "23300099");

    int choice;
    string nama, nim, posisi_setelah;
    while (true) {
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
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
            case 3:
                cout << "-Tambah Tengah-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Nama Posisi Setelah : ";
                cin >> posisi_setelah;
                tambahTengah(nama, nim, posisi_setelah);
                break;
            case 11:
                tampilData();
                break;
            case 0:
                hapusList();
                cout << "Terima kasih!" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
