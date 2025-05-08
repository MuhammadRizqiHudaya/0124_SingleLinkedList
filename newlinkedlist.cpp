#include <iostream>
using namespace std;

class node {
public:
    int nomhs;
    node *next;
};

class list {
    node *START;

public:
    list() {
        START = NULL;
    }

    void addnode() {
        int nim;
        cout << "\nMasukkan nomor mahasiswa: ";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->nomhs = nim;

        if (START == NULL || nim <= START->nomhs) {
            if ((START != NULL) && (nim == START->nomhs)) {
                cout << "\nDuplikasi nomhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        node *previous = START;
        node *current = START;

        while ((current != NULL) && (nim >= current->nomhs)) {
            if (nim == current->nomhs) {
                cout << "\nDuplikasi nomhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodebaru->next = current;
        previous->next = nodebaru;
    }

    bool listempty() {
        return (START == NULL);
    }

    bool search(int nim, node **previous, node **current) {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->nomhs)) {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delnode(int nim) {
        node *current, *previous;
        if (!search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse() {
        if (listempty()) {
            cout << "\nList Kosong\n";
        } else {
            cout << "\nData didalam list adalah:\n";
            node *current = START;
            while (current != NULL) {
                cout << current->nomhs << endl;
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    list mhs;
    int nim;
    char ch;
    do {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch) {
            case '1': {
                mhs.addnode();
                break;
            }
            case '2': {
                if (mhs.listempty()) {
                    cout << "\nList kosong\n";
                    break;
                }
                cout << "\nMasukkan nomor mahasiswa yang akan dihapus: ";
                cin >> nim;
                if (mhs.delnode(nim) == false)
                    cout << "\nData tidak ditemukan\n";
                else
                    cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus\n";
                break;
            }
            case '3': {
                mhs.traverse();
                break;
            }
            case '4': {
                if (mhs.listempty()) {
                    cout << "\nList kosong\n";
                    break;
                }
                node *previous, *current;
                cout << "\nMasukkan nomor mahasiswa yang dicari: ";
                cin >> nim;
                if (mhs.search(nim, &previous, &current) == false)
                    cout << "\nData tidak ditemukan\n";
                else {
                    cout << "\nData ditemukan\n";
                    cout << "Nomor mahasiswa: " << current->nomhs << endl;
                }
                break;
            }
            case '5': {
                cout << "Keluar dari program.\n";
                break;
            }
            default: {
                cout << "Pilihan salah!\n";
                break;
            }
        }
    } while (ch != '5');

    return 0;
}