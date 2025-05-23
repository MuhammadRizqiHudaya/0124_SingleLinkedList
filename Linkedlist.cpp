#include <iostream>
#include <string.h>
using namespace std;

class node 
{
public:
    int nomhs;
    node*next;
};

class list
{
    node *START;

public:
    list()
    {
        START = NULL;
    }
};
    
    void addnode()
    {
        int nim;
        cout <<"\nMasukkan nomor mahasiswa:";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->nomhs = nim;

        if (START == NULL || nim <= START -> nomhs)
        {
            if ((START != NULL)&& (nim == START->nomhs))
            {
                cout << "\nduplikasi nomhs tidak diijinkan\n";
                return;
            }
        }
        nodebaru -> next = START;
        START = nodebaru;
        return; 
    };

    node *previous = START;
    node *currrent = START;

    while ((current ! = NULL)&&(nim >= current ->nomhs))
    {
        if (nim == current -> nomhs)
        {
            cout << "\nduplikasi nomhs tidak diijinkan\n;"
            return;
        }
        previous = current;
        current = current -> next
    }

    nodebaru -> next = current ;
    previous -> next = nodebaru;



    

    bool listempty()
    {
        return (START == NULL);
    }

    bool search(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL)&&(nim != (*current)->nomhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        
            return (*current != NULL);
        }

        bool delnode(int nim)
        {
            node *current, *previous;
            if (!search(nim, &previous, &current))
                return false;

            if (current == START)
                START = START-> next;
            else
                previous -> next = current -> next;

            delete current;
            return true;
        }

        void traverse()
        {
            if (listempty())
            {
                cout << "\nList Kosong\n";
            }
            else
            {
                cout << "\ndata didalam list adalah:\n";
                node *current = START;
                while (currentnode != NULL)
                {
                    cout << current -> nomhs << endl;
                    currentnode = current -> next;
                }
                cout << endl;
            }
        }
 int main()
 {
    list mhs;
    int mhs;
    char ch;
    while (1)
    {
        cout 
            << "Menu"<< endl;
        cout << endl
            << "1. menambah data kedalam list" << endl;
        cout << "2.mengahpus data dari dalam list" << endl;
        cout << "3.menampilkan semua data didalam list" << endl;
        cout << "4.mencari data dalam list" << endl;
        cout << "5.keluar" << endl;
        cout 
             << "masukkan pilihan (1-5)"<< endl;
        cin >> ch;
        switch (ch)
        {
            mhs.addnode();
            break;
        }

        case '2':
        {
            if (mhs.listempty())
            {
              cout << endl
              <<"list kosong"<< endl;
              break;
            }
            cout << endl
            <<"\nmasukkan no mahasiswa yang akan dihapus:";
            cin >> nim;
            if (mhs.delnode(nim)== false)
            cout << endl
            <<"data tidak ditemukan" << endl;
            else
            cout << endl
            <<"data dengan nomor mahasiswa" << nim << "berhasil dihapus"<< endl;
        }
        break;
        case '3':
        {
            mhs.traverse();
        }
        break;

        case '4':
        {
            if (mhs.listempty()== true)
            {
                cout << "\nlist kosong\n";
                break;
            }
            node *previous , *current;
            cout << endl
            <<"masukkan no mahasiswa yang dicari:";
            cin >> nim;
            if (mhs.search(nim, &previous, &current)== false)
            cout << endl
            <<"data ditemukan" << endl;
            cout << "\nNo mahasiswa:"<< current -> nomhs << endl;
            cout << "\n";
        }

    }
    break;
    case '5';
    {
        cout << "pilihan salah!"<< endl;
    }
    {
        break;
    }
 }while (ch != '5');
}